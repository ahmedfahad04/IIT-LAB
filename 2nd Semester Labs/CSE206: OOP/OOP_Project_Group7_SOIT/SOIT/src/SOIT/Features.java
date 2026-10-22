package SOIT;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.collections.transformation.SortedList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import java.lang.String;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Objects;
import java.util.Scanner;

public class Features extends Dependencies{

    ObservableList<Hospital> dataList = FXCollections.observableArrayList();
    FilteredList<Hospital> filteredData = new FilteredList<>(dataList, b -> true);

    public void TableManager (File fp, ArrayList<TableColumn<Hospital, String>> x, TableView tb, int filter){
        dataList.clear();
        try {

            Scanner sc = new Scanner(fp);
            while (sc.hasNext()) {
                String str = sc.nextLine();
                String[] parts = str.split(",");
                Hospital hp = null;

                if(filter == 1){ //icu

                    if(!parts[2].equals("0") && !parts[2].equals("")){
                        hp = new Hospital(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6]);
                    }
                    if(hp!= null) dataList.add(hp);

                }
                else if(filter == 0){ //oxygen

                    if(!parts[3].equals("0") && !parts[3].equals("")){
                        hp = new Hospital(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6]);
                    }
                    if(hp!= null) dataList.add(hp);
                }

                else if(filter == 2){ //both

                    if(!parts[3].equals("0") && !parts[3].equals("") && !parts[2].equals("0") && !parts[2].equals("")){
                        hp = new Hospital(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6]);
                    }
                    if(hp!= null) dataList.add(hp);
                }

                else{
                    hp = new Hospital(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6]);
                    dataList.add(hp);
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        x.get(0).setCellValueFactory(new PropertyValueFactory<>("Name"));
        x.get(1).setCellValueFactory(new PropertyValueFactory<>("Address"));
        x.get(2).setCellValueFactory(new PropertyValueFactory<>("ICU"));
        x.get(3).setCellValueFactory(new PropertyValueFactory<>("Oxygen"));
        x.get(4).setCellValueFactory(new PropertyValueFactory<>("Contact"));
        x.get(5).setCellValueFactory(new PropertyValueFactory<>("UpdateTime"));

        tb.setItems(dataList); // adding to tableview
    }

    @Override
    public void WriteFile(File fp, String content, boolean append) throws IOException {

        FileWriter fw = new FileWriter(fp, append);
        fw.write(content);
        fw.close();
    }

    @Override
    public void SearchEngine(TextField tf, TableView tb) {


        tf.textProperty().addListener((observable, oldValue, newValue) -> {
            filteredData.setPredicate(hospital -> {

                if (newValue == null || newValue.isEmpty() || hospital == null) {
                    return true;
                }

                String lowerCaseFilter = newValue.toLowerCase();

                if(!hospital.getName().equals("") && !hospital.getAddress().equals("") &&!hospital.getICU().equals("") && !hospital.getOxygen().equals("") ){
                    if (hospital.getName().toLowerCase().contains(lowerCaseFilter)) {
                        return true;
                    } else if (hospital.getAddress().toLowerCase().contains(lowerCaseFilter)) {
                        return true;
                    } else if (String.valueOf(hospital.getICU()).contains(lowerCaseFilter)) {
                        return true;
                    } else return hospital.getOxygen().toLowerCase().contains(lowerCaseFilter);
                }
                else return true;

            });
        });

        SortedList<Hospital> sortedData = new SortedList<>(filteredData);
        sortedData.comparatorProperty().bind(tb.comparatorProperty());
        tb.setItems(sortedData);
    }

    @Override
    public StringBuffer SaveData(String key, String ICU, String Oxygen, String Contact) throws IOException {
        Date thisDate = new Date();
        SimpleDateFormat dateForm = new SimpleDateFormat("MM/dd/Y h:mm a");
        String strDate = dateForm.format(thisDate);

        // save info as csv file.

        StringBuffer sb = new StringBuffer();
        File f = ReadFile("data.csv");
        String row = "", s = "";

        BufferedReader br = new BufferedReader(new FileReader(f));
        while ((s = br.readLine()) != null) {

            String[] parts = s.split(",");

            if (parts[6].equals(key)) {
                row += parts[0] + "," + parts[1] + ",";

                parts[2] = ICU;
                parts[3] = Oxygen;
                parts[4] = Contact;
                parts[5] = strDate;

                row += parts[2] + "," + parts[3] + "," + parts[4] + "," + parts[5] + "," + parts[6] + "\n";
                sb.append(row);
                System.out.println(row);

            } else {
                sb.append(s); //goto next line
                sb.append("\n");

            }
            Hospital h1 = new Hospital(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6]);
            dataList.add(h1);
        }
        return sb;
    }
}