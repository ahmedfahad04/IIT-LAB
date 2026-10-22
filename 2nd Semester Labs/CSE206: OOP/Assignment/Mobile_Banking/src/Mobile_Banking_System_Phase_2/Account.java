// Parent Class
package Mobile_Banking_System_Phase_2;


public class Account {
    private String account_holder_name;
    private String mobile_number;
    private double balance;
    private double cash_out_charge;
    private String pin;


    // constructor
    public Account(String user_name, String phone_num, String pin) {
        this.mobile_number = phone_num;
        this.account_holder_name = user_name;
        this.pin = pin;
    }

    //==> Different operations(cash out, add money, send money, update pin, to string)
    // cash out
    void withdraw(double amount, String pin_code) {
        System.out.println("\nCASH OUT: ");
        if (this.pin.equals(pin_code)) {

            if (amount > balance) {
                System.out.println("  Cash out Failed due to insufficient Balance.");
            }

            else {

                double withdraw_amount = (amount + (cash_out_charge * (amount/1000)));
                this.balance -= withdraw_amount;
                System.out.println("  Cash out: " + amount);
                System.out.println("  "+withdraw_amount + "/-" + " taka (including vat) cashed out successfully.");
                System.out.println("Current Balance: " + balance);
            }

        }

        else {
            System.out.println("  Wrong Pin. Money withdrawal failed!!!");
        }

    }

    // add money
    void add_money(double amount2) {
        System.out.println("\nADD MONEY: ");
        if(amount2 > 30000){
            System.out.println("  Cash IN limitation crossed. Failed to Add Money!!!");
        }
        else{
            this.balance += amount2;
            System.out.println("  Successfully Added " + amount2 + "/- tk in your account.");
            System.out.println("Current Balance: " + balance);
        }

    }

    // send money
    void send_money(double amount3, String reciever, String pin_code) {
        System.out.println("\nSEND MONEY: ");
        if (reciever != null) {

            if(amount3 > 25000 || amount3 > balance){
                System.out.println("  Send Money limitation exceeded. Failed to Send Money!!!");
            }

            else{

                if (this.pin.equals(pin_code)) {

                    if (amount3 > 500) {
                        this.balance -= (amount3 + 5);
                        System.out.println("  Send Money: " + amount3);
                        System.out.println("  "+(amount3 + 5) + "/-" + " taka (including vat) sent successfully.");
                    }

                    else {
                        this.balance -= amount3;
                        System.out.println("  "+amount3 + "/-" + " taka sent successfully.");

                    }

                }

                else {
                    System.out.println("  Wrong Pin. Transaction Failed.");
                }

            }
            System.out.println("Current Balance: " + balance);
        }

        else {
            System.out.println("  Receiver number was empty. Transaction Failed!!!");
        }
    }

    // change old pin
    void change_pin(String old_pin, String new_pin) {
        if (this.pin.equals(old_pin)) {
            this.pin = new_pin;
            System.out.println("\nPin updated successfully!!");
        }
        else System.out.println("\nPin update failed. Old pin doesn't matched.");
    }

    // setting new pin
    void set_new_pin(String phone_num, String new_pin){
        System.out.println("\nTo set new pin first you need confirm your mobile number.");

        if(phone_num.equals(this.mobile_number)) {

            System.out.println("Mobile number confirmed.");
            this.pin = new_pin;
            System.out.println("Pin setting successful!!");

        }

        else System.out.println("Wrong number. Failed to set new pin.");

    }

    @Override
    public String toString() {
        return "\nAccount Details, \n" +
                "--------------------------------------------------------------\n" +
                "\tAccount Holder Name:- " + account_holder_name + '\n' +
                "\tMobile Number:- " + mobile_number + '\n' +
                "\tBalance:- " + balance + "/-" +'\n';

    }

    //==> function to edit Cash_out_charge
    public void setCash_out_charge(double charge){
        this.cash_out_charge = charge;
    }

}
