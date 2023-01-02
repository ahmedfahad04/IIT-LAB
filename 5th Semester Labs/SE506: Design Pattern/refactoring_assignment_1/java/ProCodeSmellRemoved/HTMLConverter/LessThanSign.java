package ProCodeSmellRemoved.HTMLConverter;

public class LessThanSign implements SpecialCharacterMatcher {

    @Override
    public boolean compareSign(String sign) {
        return sign.equals("<");
    }

    public String getSign() {
        return "&lt;";
    }
}