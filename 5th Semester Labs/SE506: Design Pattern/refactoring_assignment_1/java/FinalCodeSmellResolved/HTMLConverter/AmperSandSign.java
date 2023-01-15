package FinalCodeSmellResolved.HTMLConverter;

public class AmperSandSign implements SpecialCharacterMatcher {

    @Override
    public boolean compareSign(String sign) {
        return sign.equals("&");
    }

    public String getSign() {
        return "&amp;";
    }
}