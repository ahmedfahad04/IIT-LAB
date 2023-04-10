package Composite_Pattern_2;

public class BatchFile extends File{

    public BatchFile(String filename, double fileSize) {
        super(filename, fileSize);
    }

    @Override
    public double calculateFileSize() {
        return getFileSize();
    }
}
