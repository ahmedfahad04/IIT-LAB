package Composite_Pattern_2;

public class TextFile extends File{

    public TextFile(String filename, double fileSize) {
        super(filename, fileSize);
    }

    @Override
    public double calculateFileSize() {
        return getFileSize();
    }
}
