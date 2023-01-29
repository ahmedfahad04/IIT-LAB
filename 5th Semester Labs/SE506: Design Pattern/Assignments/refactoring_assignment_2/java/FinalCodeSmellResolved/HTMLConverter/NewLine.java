package FinalCodeSmellResolved.HTMLConverter;

public class NewLine implements SpecialCharacterMatcher {

    @Override
    public boolean compareSign(String sign) {
        return sign.equals("\n");
    }

    public String getSign() {
        return "<br />";
    }
}