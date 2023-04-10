package Composite_Pattern_2;

public abstract class File implements Folder{

    protected final String fileName;
    protected final double fileSize;

    protected File(String fileName, double fileSize) {
        this.fileName = fileName;
        this.fileSize = fileSize;
    }

    public double getFileSize() {
        return fileSize;
    }
}
