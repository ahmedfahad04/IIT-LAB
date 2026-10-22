package SOIT;

import java.io.IOException;

public interface ErrorHandler {
    
    // we can have default, statin and abstract method here. 
    public abstract void checkEmptyFields(String ...args) throws IOException;
    public abstract void keyChecker(String ...args) throws IOException;
}
