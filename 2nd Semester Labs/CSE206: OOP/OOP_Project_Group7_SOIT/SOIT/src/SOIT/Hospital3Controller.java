package SOIT;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import java.io.*;

public class Hospital3Controller extends Features implements ErrorHandler {

    @FXML
    public TextField txtContact;
    @FXML
    private StackPane stkReg; // full stack for registering hospitals
    @FXML
    private Pane pnRegDone; // Register SUCCESSFUL window
    @FXML
    private Pane pnReg; // Register window
    @FXML
    private StackPane stkHU; // full stack for stkUp(Update info) and pnHos(2nd Mainwindow)
    @FXML
    private StackPane stkUp; // full stack for updating info(pnUp, pnUpDone)
    @FXML
    private Pane pnUpDone; // update SUCCESSFUL window
    @FXML
    private Pane pnUp; // update window
    @FXML
    private Pane pnHos; // 2nd main window
    @FXML
    private Button HosToUp;
    @FXML
    private Button HosToReg;
    @FXML
    private TextField txtName;
    @FXML
    private TextField txtLoc;
    @FXML
    private TextField txtKey;
    @FXML
    private TextField txtUpKey;
    @FXML
    private TextField txtICU;
    @FXML
    private TextField txtOxy;
    @FXML
    private Label empField;
    @FXML
    private Label incorrectKey;

    @FXML
    private void bHosToReg(ActionEvent event) {
        if (event.getSource().equals(HosToReg)) {
            System.out.println("Welcome to Registration Window");
            stkReg.toFront();
            pnReg.toFront();
        }
    }

    @FXML
    private void bHosToUp(ActionEvent event) {
        if (event.getSource().equals(HosToUp)) {
            System.out.println("Welcome to Update Window");
            stkUp.toFront();
            pnUp.toFront();
        }
    }

    @FXML
    private void bHosToTable(ActionEvent event) throws IOException {
        System.out.println("Show Table List");
        LoadFXML(event.getSource(), "User.fxml");
    }

    @FXML
    public void mHosToHome(MouseEvent mouseEvent) throws IOException {
        System.out.println("Return to Home");
        LoadFXML(mouseEvent.getSource(), "home.fxml");
    }

    @FXML
    private void bUpToUpDone(ActionEvent event) throws IOException {
        updateUserInfo();
    }

    @FXML
    private void mUptoHos(MouseEvent event) {
        System.out.println("Update Window to Dashboard");
        pnHos.toFront();
    }

    @FXML
    private void bRegToRegDone(ActionEvent event) throws IOException { //registration done page
        registerUser();
    }

    @FXML
    private void mRegToHos(MouseEvent event) {
        System.out.println("Registration Window to Dashboard");
        stkHU.toFront();
        pnHos.toFront();
    }

    @FXML
    private void bRegDoneToUp(ActionEvent event) { //return to update info page
        System.out.println("Registration Done Window to Dashboard");
        stkHU.toFront();
        stkUp.toFront();
        pnUp.toFront();

    }

    @FXML
    public void bUpDonetoHos(MouseEvent mouseEvent) {
        System.out.println("Update Done Window to Dashboard");
        stkHU.toFront();
        pnHos.toFront();
    }

    public void registerUser() throws IOException {
        String name = txtName.getText();
        String location = txtLoc.getText();
        String key = txtKey.getText();
        empField.setText("");

        File f = ReadFile("data.csv");
        checkEmptyFields(f, name, location, key);

        txtKey.clear();
        txtLoc.clear();
        txtName.clear();
    }

    public void updateUserInfo() throws IOException {
        String icu = txtICU.getText();
        String oxygen = txtOxy.getText();
        String contact = txtContact.getText();
        String key = txtUpKey.getText();
        incorrectKey.setText("");

        checkEmptyFields(icu, oxygen, contact, key);

        txtICU.clear();
        txtUpKey.clear();
        txtOxy.clear();
        txtContact.clear();
    }

    
    public void checkEmptyFields(File f, String... arguments) throws IOException {
        String name = arguments[0];
        String location = arguments[1];
        String Key = arguments[2];

        String Data = name + "," + location + "," + null + "," + null + "," + null + "," + null + "," + Key + "\n";

        if (name.equals("") || location.equals("") || Key.equals("")) {
            empField.setText("You have to fill all the fields");
            txtKey.clear();
            txtLoc.clear();
            txtName.clear();
        } else {

            FileReader fr = new FileReader("data.csv");
            BufferedReader br = new BufferedReader(fr);
            String s;
            int keyflag = 0;

            while ((s = br.readLine()) != null) { // read a line
                String[] part = s.split(",");

                if (part[6].equals(Key)) {
                    keyflag = 1;
                    break;
                }
            }

            if (keyflag == 0) {

                WriteFile(f, Data, true);
                System.out.println("Info added successfully. Registration done.");
                System.out.println("REGISTRATION DONE!");

                pnRegDone.toFront();
            } else {
                empField.setText("This key Already Exists. Try another key.");
            }
        }
    }

    public void checkEmptyFields(String... arguments) throws IOException {
        String ICU = arguments[0];
        String Oxygen = arguments[1];
        String Contact = arguments[2];
        String key = arguments[3];

        if (ICU.equals("") || Oxygen.equals("") || key.equals("") || Contact.equals("")) {
            incorrectKey.setText("You have to fill all the fields");
        } else {
            keyChecker(ICU, Oxygen, Contact, key);
        }
    }

    public void keyChecker(String... arguments) throws IOException {
        String ICU = arguments[0];
        String Oxygen = arguments[1];
        String Contact = arguments[2];
        String key = arguments[3];

        FileReader fr = new FileReader("data.csv");
        BufferedReader br = new BufferedReader(fr);
        String s;
        int flag = 0;

        while ((s = br.readLine()) != null) { // read a line
            String[] data = s.split(",");
            if (data[6].equals(key)) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {

            StringBuffer sb = SaveData(key, ICU, Oxygen, Contact);
            File file = new File("data.csv");
            PrintWriter pw = new PrintWriter(new FileOutputStream(file, false));
            pw.print(sb);
            pw.close();

            System.out.println("Update DONE!!!");
            pnUpDone.toFront();
        } else {
            incorrectKey.setText("Incorrect Key");
        }
    }
}
