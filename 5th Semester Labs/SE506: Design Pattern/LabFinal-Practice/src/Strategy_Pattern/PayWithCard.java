package Strategy_Pattern;

public class PayWithCard implements Payment{

    CreditCard card = new CreditCard();

    @Override
    public void pay(double amount) {
        System.out.println("Paid with Card: " + amount);
        card.setBalance(card.getBalance() - amount);
    }

    @Override
    public boolean validate() {
        // validate
        return true;
    }
}
