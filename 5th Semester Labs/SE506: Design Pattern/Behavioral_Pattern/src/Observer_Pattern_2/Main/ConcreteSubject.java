package Observer_Pattern_2.Main;

import java.io.IOException;
import java.nio.file.*;


import static java.nio.file.StandardWatchEventKinds.*;

public class ConcreteSubject {

    Subject _subject; // we can also use the references here instead of extneding subject class

    private final String fileDirectory;

    public ConcreteSubject(String fname) {
        this.fileDirectory = fname;
        this._subject = new Subject();
    };

    public void trackFileChanges() throws IOException, InterruptedException {
        // Creates an instance of WatchServices

        WatchService watcher = FileSystems.getDefault().newWatchService();

        Path logDir = Paths.get(fileDirectory);
        logDir.register(watcher, ENTRY_CREATE, ENTRY_MODIFY, ENTRY_DELETE);

        while (true) {
            WatchKey key = watcher.take();

            for (WatchEvent<?> event : key.pollEvents()) {
                WatchEvent.Kind<?> kind = event.kind();

                if (kind == ENTRY_CREATE) {
                    _subject.Notify("Entry was CREATED on log dir.:" + event.context());
                } else if (kind == ENTRY_MODIFY) {
                    _subject.Notify("Entry was MODIFY on log dir.:" + event.context());
                } else if (kind == ENTRY_DELETE) {
                    _subject.Notify("Entry was DELETED on log dir.:" + event.context());
                }
            }
            key.reset();
        }
    };

}
