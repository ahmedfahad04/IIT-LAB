package FinalCodeSmellResolved.HTMLConverter;

public class NullCharacter implements SpecialCharacterMatcher {

    String character;
    @Override
    public boolean compareSign(String sign) {
        return sign == null;
    }

    public String getSign() {
        return "";
    }
}