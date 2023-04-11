package Composite_Pattern;

public class FileExplorer {

    private Folder folder;

    public void addFolder(Folder... folders) {
        this.folder = new CompositeFolder(folders);
    }

    public double getFolderSize() {
        return this.folder.calculateFileSize();
    }
}
