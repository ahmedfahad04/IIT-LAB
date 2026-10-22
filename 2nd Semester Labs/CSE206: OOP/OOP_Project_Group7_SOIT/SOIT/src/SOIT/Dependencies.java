package SOIT;

import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public abstract class Dependencies {
    
    // we can have only abstract, non-abstract(method body must) and final method here.
    // all abstract methods
    abstract void SearchEngine(TextField tf, TableView tb);
    abstract void WriteFile(File fp, String content, boolean b) throws IOException;
    abstract void TableManager(File fp, ArrayList<TableColumn<Hospital, String>> x, TableView tb, int filter);
    abstract StringBuffer SaveData(String key, String ICU, String Oxygen, String Contact) throws IOException;
    
    //its made final so that the subclasses cant have the access of changing its body.
    final <T> void LoadFXML(T event, String fxmlName) throws IOException{ 
        Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource(fxmlName)));
        Stage stage = (Stage) ((Node) event).getScene().getWindow();
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    };
    
    // we also mentioned some non-abstact methods
    File ReadFile(String fileName){
        
        File f = new File(fileName);
        if (!f.exists()) {
            try {
                f.createNewFile();
                System.out.println("New file created successfully!!");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return f;
    };
    
}