#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget* parent )
   : QMainWindow( parent )
   , ui( new Ui::MainWindow )
{
   ui->setupUi( this );
   audio = new AudioVisualizerWidget;
   ui->horizontalLayout->addWidget( audio );
   audio->show();
   ui->quickWidget->setSource(QUrl("qrc:/PlanetsMain.qml"));
   ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

MainWindow::~MainWindow()
{
   delete audio;
   delete ui;
}
