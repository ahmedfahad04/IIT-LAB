package FinalCodeSmellResolved.HTMLConverter;

public class EndSign implements SpecialCharacterMatcher {

    @Override
    public boolean compareSign(String sign) {
        return sign.equals("&");
    }

    public String getSign() {
        return "<br />";
    }
}