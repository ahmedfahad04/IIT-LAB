package Mobile_Banking_System_Phase_1;

public class User {
    public void show_account_details(){

        Account_info asif = new Account_info("Asif Ahmed Chowdhury", "01766610087");// user without pin
        Account_info safiyah = new Account_info("Safiyah Sultana", "01766610085", "8523");

        // add money
        asif.add_money(4000);
        // as he don't have any pin; here he will set a new pin to cash out money.
        if(asif.getPin() == null) asif.set_new_pin();
        // cash out
        asif.cash_out(2000, asif.getPin());

        // show user details
        System.out.println(asif.toString());
        System.out.println("-----------------------------------------------\n");

        safiyah.add_money(2500);
        // user can also change his pin.
        safiyah.change_pin("85235","2589");
        // check whether user have any prior pin to access cash out.
        if(safiyah.getPin() == null) safiyah.set_new_pin();
        safiyah.cash_out(300, safiyah.getPin());

        System.out.println(safiyah.toString());
        System.out.println("-----------------------------------------------\n");

    }
}
