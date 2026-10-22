package Mobile_Banking_System_Phase_1;

import java.util.Scanner;

public class Account_info {
    Scanner sc = new Scanner(System.in);
    private String account_holder_name ;
    private String account_holder_mobile_number;
    private double balance;
    private String pin;


    //==> constructor (one for general registration, another for without pin registration)
    // constructor 1(general user)
    public Account_info(String user_name, String user_phone, String user_pin){
        this.account_holder_name = user_name;
        this.account_holder_mobile_number = user_phone;
        this.pin = user_pin;
    }

    // constructor 2(user register without pin)
    public Account_info(String user_name, String user_phone){
        this.account_holder_name = user_name;
        this.account_holder_mobile_number = user_phone;
    }


    //---------------------------------------------------------------------------------------------------------
    //==> different account operations (cash out, add money, change pin, set new pin, to string)
    // cash out
    void cash_out(int amount, String pin_code){
        if(this.pin.equals(pin_code)){
            if(amount > balance){
                System.out.println("-->Cash out Failed due to insufficient Balance.");
            }
            else {
                this.balance -= amount;
                System.out.println("-->Successfully Cashed out " + amount + "/- tk.");
            }
        }
        else{
            System.out.println("-->Wrong Password. Access Denied!");
        }
    }

    // add money
    void add_money(int amount2){
        this.balance += amount2;
        System.out.println("-->Successfully Added " + amount2 + "/- tk in your account.");
    }

    // change old pin
    void change_pin(String old_pin, String new_pin){
        if(this.pin.equals(old_pin)){
            this.pin = new_pin;
            System.out.println("-->Pin updated successfully!!");
        }
        else System.out.println("-->Pin update failed. Old pin doesn't matched.");
    }

    //setting new pin
    void set_new_pin(){
        String updated_pin, phone_num;
        System.out.println("-->Sorry! Without pin you cant Cash out..");
        System.out.println("-->To confirm your identity first you need to enter your mobile number.");
        System.out.println("-->Enter your mobile number: ");


        while(true){
            phone_num = sc.nextLine();

            if(phone_num.equals(this.account_holder_mobile_number)) {

                System.out.println("-->Mobile no. confirmed.\n-->Enter your new pin(max 4 character): ");
                updated_pin = sc.nextLine();
                this.pin = updated_pin;
                System.out.println("-->New Pin setting successful!!");
                break;

            }

            else System.out.println("-->Wrong number. Enter again: ");
        }
    }


    // to-string usage
    @Override
    public java.lang.String toString() {
        return "\nAccount_info: \n" +
                "Name: " + account_holder_name + "\n" +
                "Phone: " + account_holder_mobile_number + "\n" +
                "Balance: " + balance;
    }

    //---------------------------------------------------------------------------------------------------------
    //==> methods for accessing private variables.
    // show balance
    void my_balance(){
        System.out.println("Current Balance: " + this.balance);
    }

    // show user name
    public void getAccount_holder_name(){
        System.out.println("Name: " + this.account_holder_name);
    }

    // show user phone number
    public void getAccount_holder_mobile_number(){
        System.out.println("Cell: " + this.account_holder_mobile_number);
    }

    // show the user pin
    public String getPin(){
        return this.pin ;
    }

}
