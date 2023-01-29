package SlightSmellRemoved;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

class HTMLEncoder {

    private String source;
    private int i;
    private List<String> result;
    private List<String> convertedLine;
    private String characterToConvert;

    public String basicHtmlEncode(String source) {
        result = new ArrayList<>();

        encodeSourceText(source);

        stringifyConvertedLineAndReset();
        String finalResult = String.join("<br />", result);
        return finalResult;
    }

    private void encodeSourceText(String source){

        i = 0;
        this.source = source;
        convertedLine = new ArrayList<>();
        characterToConvert = pickCharacterAndIncrementPointer();

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
                    stringifyConvertedLineAndReset();
                    break;
                default:
                    pushACharacterToTheOutput();
            }

            if (i >= source.length()) break;

            characterToConvert = pickCharacterAndIncrementPointer();
        }

    }

    private String pickCharacterAndIncrementPointer() {
        char c = source.charAt(i);
        i += 1;
        return String.valueOf(c);
    }

    private void stringifyConvertedLineAndReset() {
        String line = String.join("", convertedLine);
        result.add(line);
        convertedLine = new ArrayList<>();
    }

    private void pushACharacterToTheOutput() {
        convertedLine.add(characterToConvert);
    }

}

public class PlaintextToHtmlConverter {

    public String toHtml() throws Exception {
        String text = read();
        return new HTMLEncoder().basicHtmlEncode(text);
    }

    protected String read() throws IOException {
        return new String(Files.readAllBytes(Paths.get("sample.txt")));
    }

}
