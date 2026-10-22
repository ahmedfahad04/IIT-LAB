package SOIT;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;

import java.io.File;

import java.io.IOException;
import java.net.URL;
import java.util.*;


public class UserController extends Features implements Initializable {

    ArrayList<TableColumn<Hospital, String>> AllColumns = new ArrayList<>();


    @FXML
    private StackPane stkReport;
    @FXML
    private Pane pnReported;
    @FXML
    private Pane pnIssue;
    @FXML
    private TextArea txtIssue;
    @FXML
    private Button reportSubmit;
    @FXML
    private Pane pnTable;
    @FXML
    private TableView<Hospital> table;
    @FXML
    private TableColumn<Hospital, String> colName;
    @FXML
    private TableColumn<Hospital, String> colLoc;
    @FXML
    private TableColumn<Hospital, String> colICU;
    @FXML
    private TableColumn<Hospital, String> colOxy;
    @FXML
    private TableColumn<Hospital, String> colContact;
    @FXML
    private TableColumn<Hospital, String> colUpdate;
    @FXML
    private TextField searchBar;
    @FXML
    private Label tableToReport;
    @FXML
    private ImageView issueToTable;
    @FXML
    private CheckBox chkICU;
    @FXML
    private CheckBox chkOxygen;

    void fetchData() {
        AllColumns.add(colName);
        AllColumns.add(colLoc);
        AllColumns.add(colICU);
        AllColumns.add(colOxy);
        AllColumns.add(colContact);
        AllColumns.add(colUpdate);
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        File f = ReadFile("data.csv");
        fetchData();

        TableManager(f, AllColumns, table, 3);
        SearchEngine(searchBar, table);
    }

    @FXML
    void showChkResult(MouseEvent event) {
        boolean icu = chkICU.isSelected();
        boolean oxy = chkOxygen.isSelected();

        int filter = 3; //with blank entry

        if (!icu && oxy) filter = 0; //only oxygen
        else if (!oxy && icu) filter = 1; // oxygen
        else if (oxy && icu) filter = 2; // both

        File f = ReadFile("data.csv");
        fetchData();

        TableManager(f, AllColumns, table, filter);
        SearchEngine(searchBar, table);
    }

    @FXML
    private void tableToReport(MouseEvent event) {
        if (event.getSource().equals(tableToReport)) {
            stkReport.toFront();
            pnIssue.toFront();
        }
    }

    @FXML
    private void issueToTable(MouseEvent event) {
        if (event.getSource().equals(issueToTable)) {
            pnTable.toFront();
        }
    }

    @FXML
    public void switchToHome(MouseEvent event) throws IOException {
        LoadFXML(event.getSource(), "home.fxml");
    }

    @FXML
    public void switchToHome2(ActionEvent event) throws IOException {
        LoadFXML(event.getSource(), "home.fxml");
    }

    @FXML
    private void reportSubmit(ActionEvent event) throws IOException {
        if (event.getSource().equals(reportSubmit)) {
            pnReported.toFront();
            String data = ">> " + txtIssue.getText() + "\n";

            if (txtIssue.getText() != null) {
                File fp = ReadFile("Report.txt");
                WriteFile(fp, data, true);
            }
        }
    }


}