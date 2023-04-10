package Composite_Pattern_2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CompositeFolder implements Folder{
    List<Folder> folders = new ArrayList<Folder>();

    public CompositeFolder(Folder... folders) {
        this.folders.addAll(Arrays.asList(folders));
    }

    @Override
    public double calculateFileSize() {
        return this.folders.stream().mapToDouble(Folder::calculateFileSize).sum();
    }
}
