package SOIT;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import java.io.IOException;

public class HomeController extends Features{

    @FXML
    public void switchToUser(ActionEvent event) throws IOException {
        LoadFXML(event.getSource(), "User.fxml");
    }

    @FXML
    public void switchToHospital(ActionEvent event) throws IOException {
        LoadFXML(event.getSource(), "Hospital3.fxml");
    }
    
}
