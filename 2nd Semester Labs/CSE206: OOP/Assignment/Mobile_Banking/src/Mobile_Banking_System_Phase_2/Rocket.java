package Mobile_Banking_System_Phase_2;

public class Rocket extends Account{

    public Rocket(String accName, String acc_phone_no, String pin_code){
        super(accName, acc_phone_no, pin_code);
    }


    @Override
    void withdraw(double amount, String pin_code) {
        setCash_out_charge(18); // per thousand

        // check money limit
        if(amount > 25000){
            System.out.println("Cash Out Limitation exceeded. Failed to Withdraw Money!!!");
        }
        else super.withdraw(amount, pin_code);
    }
}
