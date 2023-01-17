public class PDFConverter extends ConverterManager {

    // CONCRETE CREATOR A

    @Override
    public Converter convert() {
        return new PDFToWordConverter();
    }

    @Override
    public Merger mergeDocument() {
        return new PDFMerger();
    }

}
