public class WordConverter extends ConverterManager {

    // CONCRETE PRODUCT B
    @Override
    public Converter convert() {
        return new WordToPDFConverter();
    }

    @Override
    public Merger mergeDocument() {
        return new WordDocMerger();
    }
}
