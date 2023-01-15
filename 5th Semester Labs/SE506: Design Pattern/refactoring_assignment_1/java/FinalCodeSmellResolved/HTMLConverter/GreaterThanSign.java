package FinalCodeSmellResolved.HTMLConverter;

public class GreaterThanSign implements SpecialCharacterMatcher {

    @Override
    public boolean compareSign(String sign) {
        return sign.equals(">");
    }

    public String getSign() {
        return "&gt;";
    }
}