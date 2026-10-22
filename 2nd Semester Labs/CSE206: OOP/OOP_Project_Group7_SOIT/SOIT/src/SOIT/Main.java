package SOIT;

import java.io.IOException;
import java.util.Objects;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {

        Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("start.fxml")));
        Scene scene = new Scene(root);
        stage.getIcons().add(new Image(Objects.requireNonNull(Main.class.getResourceAsStream("Appicon.png"))));
        stage.setTitle("S O I T");
        stage.setScene(scene);
        stage.show();
        stage.setResizable(false);
        Timeline timeline = new Timeline(new KeyFrame(Duration.millis(750),
            ae -> {
                stage.close();
                Parent root1;
                try {
                    root1 = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("home.fxml")));
                    Scene scene1 = new Scene(root1);
                    stage.setScene(scene1);
                    stage.show();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }));
        timeline.play();
    }
}
