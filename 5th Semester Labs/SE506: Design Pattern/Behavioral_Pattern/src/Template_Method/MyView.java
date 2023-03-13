package Template_Method;

public class MyView extends View {

    @Override
    public void DoDisplay() {
        System.out.println("Drawing MyView");
    }

    // Be careful that, if you don't override the Template method (Display)
    
    public static void main(String[] args) {
        View view = new MyView();
        view.Display();
    }
}
  
