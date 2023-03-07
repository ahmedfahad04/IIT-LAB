package Template_Method;

public abstract class View {

    // This is the template method that defines the overall algorithm
    public final void Display() {
        
        SetFocus();

        // This is the hook method
        // That perform the actual drawing
        DoDisplay();

        ResetFocus();
    }


    // Concrete Operation
    // as it's implementation is done in the base class
    protected void SetFocus() {
        System.out.println("Setting focus");
    }

    // Concrete Operation
    // as it's implementation is done in the base class
    protected void ResetFocus() {
        System.out.println("Resetting focus");
    } 
    
    // This is the hook method, which has a default implementation
    // or it might not have any implementation at all
    public abstract void DoDisplay();



}
