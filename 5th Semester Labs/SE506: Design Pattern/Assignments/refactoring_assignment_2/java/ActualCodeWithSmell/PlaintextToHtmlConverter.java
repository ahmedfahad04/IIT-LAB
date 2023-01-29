package ActualCodeWithSmell;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class PlaintextToHtmlConverter {
    String source;
    int i;
    List<String> result;
    List<String> convertedLine;
    String characterToConvert;

    public String toHtml() throws Exception {
        String text = read();
        String htmlLines = basicHtmlEncode(text);
        return htmlLines;
    }

    public String read() throws IOException {
        return new String(Files.readAllBytes(Paths.get("/home/fahad/Documents/IIT-LAB/refactoring-workshop/java/src/main/java/ResolvedPart2/HTMLConverter/demo.txt")));
    }

    private String basicHtmlEncode(String source) {
        this.source = source;
        i = 0;
        result = new ArrayList<>();
        convertedLine = new ArrayList<>();
        characterToConvert = stashNextCharacterAndAdvanceThePointer();

        while (i <= this.source.length()) {
            switch (characterToConvert) {
                case "<":
                    convertedLine.add("&lt;");
                    break;
                case ">":
                    convertedLine.add("&gt;");
                    break;
                case "&":
                    convertedLine.add("&amp;");
                    break;
                case "\n":
                    addANewLine();
                    break;
                default:
                    pushACharacterToTheOutput();
            }

            if (i >= source.length()) break;

            characterToConvert = stashNextCharacterAndAdvanceThePointer();
        }
        addANewLine();
        String finalResult = String.join("<br />", result);
        return finalResult;
    }

    //pick the character from source string
    //and increment the pointer
    private String stashNextCharacterAndAdvanceThePointer() {
        char c = source.charAt(i);
        i += 1;
        return String.valueOf(c);
    }

    //stringfy convertedLine array and push into result
    //reset convertedLine
    private void addANewLine() {
        String line = String.join("", convertedLine);
        result.add(line);
        convertedLine = new ArrayList<>();
    }

    private void pushACharacterToTheOutput() {
        convertedLine.add(characterToConvert);
    }

    public static void main(String[] args) throws Exception {
        PlaintextToHtmlConverter plaintextToHtmlConverter = new PlaintextToHtmlConverter();
        String convTxt = plaintextToHtmlConverter.toHtml();
        System.out.println(convTxt);
    }
}
