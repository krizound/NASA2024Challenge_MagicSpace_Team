# Exoplanet Vitality Explorer
 A program for interaction of the application core with a model whose algorithm is to determine life on the planet and mineral. Contains both the kernel and the graphics component. 
The algorithms of the application interact through QProcess with the Python model, with subsequent output to the qml graphical component for display to the user.

QProcess is used to establish communication between the C++ application and the Python model. This allows for efficient data exchange and real-time processing.
In the application core, an object of the QProcess class is created with the parameters for reading the I/O stream set, and the signal is connected to the function. Note that a signal will be emitted every time a newline character - "\n" - is sent in the python output.

QML is used for rendering the graphical user interface, enabling dynamic and interactive visualizations of the planetary viability and mineral analysis data to end-users.

I would like to say that this method of communication allows us to strictly delineate the areas of responsibility of people and in professional development to achieve a microservice application architecture. This allows you to combine different parts of the application to ensure a modular architecture, the application is separated from the graphics display, so if you have a JS developer, you can issue this data to localhost for web data presentation
