# Exoplanet Vitality Explorer
Analyzing Exoplanets for Life and Valuable Resources

![alt text](https://github.com/krizound/NASA2024Challenge_MagicSpace_Team/blob/main/video_work.gif)

A program for interaction of the application core with a model whose algorithm is to determine life on the planet and mineral. Contains both the kernel and the graphics component. 
The algorithms of the application interact through QProcess with the Python model, with subsequent output to the qml graphical component for display to the user.

AI use our repo - https://github.com/Kostratana/EVE_2024NASA_Challenge_MagicSpace_Team :
The project is based on the use of data from the NASA Exoplanet Archive https://exoplanetarchive.ipac.caltech.edu/cgi-bin/nstedAPI/nph-nstedAPI? to analyze candidates for exoplanet status, aiming to predict their ability to support life and the presence of water. The code extracts data about these candidate exoplanets through the NASA API, processes it into a DataFrame, and displays the first few rows of the data. It normalizes various characteristics of the candidates, calculates new parameters, such as the product of orbital periods and stellar insolation, and adds binary indicators for the possibility of life based on temperature. Furthermore, the project includes the creation of a classification model using the Random Forest algorithm, which is trained on balanced data using the SMOTE method to improve predictions. The results indicate that some candidates, such as K07849.01 and K03395.02, have high chances of habitability, while others, like K07106.01, are not suitable for life. Additionally, the project predicts the probability of water presence on the candidate exoplanets, with K07849.01 showing the highest probability (0.60), followed closely by K07106.01 (0.58), indicating their potential to support life. Overall, the project demonstrates how NASA data can be utilized to analyze candidate exoplanets and predict their suitability for life, as well as the presence of water, which is a key factor for future research and colonization of other planets.

Links to libraries : requests: https://docs.python-requests.org/en/latest/ pandas: https://pandas.pydata.org/docs/ io: https://docs.python.org/3/library/io.html scikit-learn: https://scikit-learn.org/stable/ numpy: https://numpy.org/doc/stable/ imblearn: https://imbalanced-learn.org/stable/ seaborn: https://seaborn.pydata.org/ matplotlib: https://matplotlib.org/stable/contents.html
QProcess is used to establish communication between the C++ application and the Python model. This allows for efficient data exchange and real-time processing.
In the application core, an object of the QProcess class is created with the parameters for reading the I/O stream set, and the signal is connected to the function. Note that a signal will be emitted every time a newline character - "\n" - is sent in the python output.

QML is used for rendering the graphical user interface, enabling dynamic and interactive visualizations of the planetary viability and mineral analysis data to end-users.

I would like to say that this method of communication allows us to strictly delineate the areas of responsibility of people and in professional development to achieve a microservice application architecture. This allows you to combine different parts of the application to ensure a modular architecture, the application is separated from the graphics display, so if you have a JS developer, you can issue this data to localhost for web data presentation
