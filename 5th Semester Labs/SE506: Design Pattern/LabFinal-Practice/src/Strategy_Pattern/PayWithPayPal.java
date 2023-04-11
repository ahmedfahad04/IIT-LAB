package Strategy_Pattern;

public class PayWithPayPal implements Payment{

    PayPal paypal = new PayPal();

    @Override
    public void pay(double amount) {
        System.out.println("Paid with Paypal: " + amount);
        paypal.setBalance(paypal.getBalance() - amount);
    }

    @Override
    public boolean validate() {
        // validate
        return true;
    }
}
