package ProCodeSmellRemoved.HTMLConverter;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

/*
    Remember:
    * Before refactoring, understand what the code actually doing.
    * We can change the behaviour of any code without affecting the logic. Like introducing or
    replacing any method/field for easy execution.
 */


/*
    1. If-else/Switch Code Smell [resolve: Strategy Pattern]
    {basicHtmlEncodes()}

    2. Inappropriate Naming [resolve: rename the names]
    {field c,i, result<list>; method stashNextCharacterAndAdvanceThePointer();}

    3. Temporary Field [resolve: remove the temp field]
    {finalResult, htmlLines}

    4. Dead code [resolve: delete method]
    {pushACharacterToTheOutput(), addNewLine(), stashNextCharacterAndAdvanceThePointer()}

    5. Long Method [resolve: Decompose conditional(switch statement), Extract Method]
    {basicHtmlEncoder()}

    6. Comment [resolve: rename method]
    {stashNextCharacterAndAdvanceThePointer(), addNewLine()}
*/

public class PlaintextToHtmlConverter {
    private String source;
    private String convLine = "";

    private final List<SpecialCharacterMatcher> signStrategies = List.of(
            new AmperSandSign(),
            new GreaterThanSign(),
            new LessThanSign(),
            new NewLine(),
            new DefaultCharacter() // order is a must, but how to resolve without proper ordering?
    );

    public String toHtml() {
        return basicHtmlEncode();
    }

    protected void read(String fileName) throws IOException {
        setSource(new String(Files.readAllBytes(Paths.get(fileName))));
    }

    private String basicHtmlEncode() {
        for(Character characterToConvert: source.toCharArray()) {
            for(SpecialCharacterMatcher strategy: signStrategies) {
                if (strategy.compareSign(String.valueOf(characterToConvert))) {
                    convLine = convLine.concat(strategy.getSign());
                    break;
                }
            }
        }

        return convLine;
    }

    public void setSource(String source){
        this.source = source;
    }


//    public static void main(String[] args) throws Exception {
//        PlaintextToHtmlConverter plaintextToHtmlConverter = new PlaintextToHtmlConverter();
//
//        plaintextToHtmlConverter.read("/home/fahad/Documents/IIT-LAB/refactoring-workshop/java/src/main/java/ResolvedPart2/HTMLConverter/demo.txt");
//        String convTxt = plaintextToHtmlConverter.toHtml();
//        System.out.println(convTxt);
//    }
}
