package Strategy_Pattern;

public class PaymentService {

    private Payment payment;
    private double amount;

    public void processPayment() {
        if(payment.validate()) {
            payment.pay(getAmount());
        }
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public double getAmount(){
        return this.amount;
    }

    public void setPaymentMethod(Payment paymentMethod) {
        this.payment = paymentMethod;
    }

}
