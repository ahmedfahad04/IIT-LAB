package Strategy_Pattern;

public class PayWithMasterCard implements Payment{

    MasterCard card = new MasterCard();
    @Override
    public void pay(double amount) {
        System.out.println("Paid with MasterCard: " + amount);
        card.setBalance(card.getBalance() - amount);
    }

    @Override
    public boolean validate() {
        return true;
    }
}
