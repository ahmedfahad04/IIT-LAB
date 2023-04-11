package Composite_Pattern;

public class ReadmeFile extends File{

    public ReadmeFile(String fileName, double fileSize){
        super(fileName, fileSize);
    }

    @Override
    public double calculateFileSize() {
        return getFileSize();
    }
}
