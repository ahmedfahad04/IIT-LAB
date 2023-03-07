package singleton_pattern;

public class Main {

    public static void main(String[] args) {

        // here main window class following the singleton pattern
        // because each application is based on one MainWindow
        // where the other widgets are placed to make the
        // whole application.
        MainWindow mainWindow = MainWindow.getInstance();

        PushButton pushButton = new PushButton("MyButton1");
        mainWindow.addWidget(pushButton);

        // thus we'll add many widgets into our mainwindow
        mainWindow.getWidgetNames();
    }
}
