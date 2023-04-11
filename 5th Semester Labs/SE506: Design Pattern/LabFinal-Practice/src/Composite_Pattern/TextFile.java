package Composite_Pattern;

public class TextFile extends File{

    public TextFile(String filename, double fileSize) {
        super(filename, fileSize);
    }

    @Override
    public double calculateFileSize() {
        return getFileSize();
    }
}
