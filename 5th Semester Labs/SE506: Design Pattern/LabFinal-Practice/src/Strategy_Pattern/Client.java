package Strategy_Pattern;

public class Client {

    public static void main(String[] args) {
        PaymentService paymentService = new PaymentService();
        paymentService.setPaymentMethod(new PayWithMasterCard());
        paymentService.processPayment();
    }

}
