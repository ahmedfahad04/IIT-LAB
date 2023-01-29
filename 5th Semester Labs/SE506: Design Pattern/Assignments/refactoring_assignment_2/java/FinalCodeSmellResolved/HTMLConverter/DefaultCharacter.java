package FinalCodeSmellResolved.HTMLConverter;

public class DefaultCharacter implements SpecialCharacterMatcher {

    String character;
    @Override
    public boolean compareSign(String sign) {
//        System.out.println(sign);
        this.character = sign;
        return true;
    }

    public String getSign() {
        return character;
    }
}