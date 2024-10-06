#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuickWidgets/QtQuickWidgets>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class AudioVisualizerWidget : public QWidget {
    Q_OBJECT

private:
    static const int barCount = 100;  // Количество полосок
    int barHeights[barCount];         // Массив высот полосок
    QTimer *timer;                    // Таймер для анимации

public:
    AudioVisualizerWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Инициализация высот полосок случайными значениями
        for (int i = 0; i < barCount; i++) {
            barHeights[i] = QRandomGenerator::global()->bounded(10, 100);
        }

        // Настройка таймера для обновления виджета каждые 50 мс
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &AudioVisualizerWidget::updateBars);
        timer->start(50);

        setMinimumSize(200, 200);  // Устанавливаем минимальный размер виджета
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        QColor color = "#b833c5";

        // Черный фон
        painter.fillRect(rect(), Qt::transparent);

        // Отрисовка полосок
        int barWidth = width() / barCount;  // Ширина каждой полоски
        for (int i = 0; i < barCount; i++) {
            int barHeight = barHeights[i];
            int x = i * barWidth;
            int y = height() - barHeight;

            //QColor color = QColor::fromHsv((i * 5) % 360, 255, 255);
            painter.setBrush(color);
            painter.drawRect(x, y, barWidth - 2, barHeight);
        }
    }

private slots:
    void updateBars() {
        // Изменение высоты полосок для создания эффекта анимации
        for (int i = 0; i < barCount; i++) {
            barHeights[i] = QRandomGenerator::global()->bounded(10, 50);
        }
        update();  // Перерисовка виджета
    }
};

class CircleWidget : public QWidget {
    Q_OBJECT

private:
    int value = 0;            // Значение числа
    int maxValue = 100;       // Максимальное значение
    int arcLength = 0;        // Длина дуги (в градусах)

public:
    CircleWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(200, 200);  // Устанавливаем фиксированный размер виджета
    }

protected:
    // Переопределение события рисования
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Рисование окружности с синей пунктирной линией
        QPen penBlue(Qt::blue, 2, Qt::DotLine);
        painter.setPen(penBlue);
        QRectF rect(10, 10, 180, 180);
        painter.drawEllipse(rect);

        // Рисование дуги (желтая часть)
        QPen penYellow(Qt::yellow, 6);
        painter.setPen(penYellow);
        painter.drawArc(rect, 90 * 16, -arcLength * 16);  // Угол в шестнадцатеричной системе

        // Рисование текста (числа)
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 40));
        painter.drawText(rect, Qt::AlignCenter, QString::number(value));
    }

    // Переопределение события клика мыши
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            value = (value + 1) % (maxValue + 1);  // Увеличиваем значение
            arcLength = (360 * value) / maxValue;  // Рассчитываем длину дуги в зависимости от значения
            update();  // Перерисовываем виджет
        }
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AudioVisualizerWidget* audio;
};
#endif // MAINWINDOW_H
