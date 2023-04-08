package Template_Method;

public abstract class View {

    // This is the template method that defines the overall algorithm
    public final void Display() {
        
        SetFocus();

        DoDisplay();

        ResetFocus();
    }


    // Concrete Operation
    // as it's implementation is done in the base class
    protected void SetFocus() {
        System.out.println("Setting focus");
    }

    // Concrete Operation
    // as it's implemResetFocusentation is done in the base class
    protected void ResetFocus() {
        System.out.println("Resetting focus");
    } 
    
    
    public abstract void DoDisplay();



}
