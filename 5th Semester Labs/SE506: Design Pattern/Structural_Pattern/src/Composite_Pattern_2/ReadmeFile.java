package Composite_Pattern_2;

public class ReadmeFile extends File{

    public ReadmeFile(String fileName, double fileSize){
        super(fileName, fileSize);
    }

    @Override
    public double calculateFileSize() {
        return getFileSize();
    }
}
