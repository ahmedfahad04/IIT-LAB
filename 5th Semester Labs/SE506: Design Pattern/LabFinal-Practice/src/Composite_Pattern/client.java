package Composite_Pattern;

public class client {
    public static void main(String[] args) {
        FileExplorer fileExplorer = new FileExplorer();
        fileExplorer.addFolder(
                new CompositeFolder(
                    new BatchFile("win.bat", 15.0), new ReadmeFile("read.me", 10.5)
                ),
                new CompositeFolder(
                        new CompositeFolder(
                                new TextFile("webtect.txt", 12),
                                new BatchFile("virus.bat", 4),
                                new ReadmeFile("notes.md", 30)
                        ),
                        new TextFile("pattern.txt", 25),
                        new BatchFile("install.bat", 20)
                )
        );

        double totalSize = fileExplorer.getFolderSize();
        System.out.println("All file sizes: " + totalSize);
    }
}
