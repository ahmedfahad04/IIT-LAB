package Template_Method;

public class client {
    public static void main(String[] args) {
        // Be careful that, if you shouldn't override the Template method (Display)

        View view = new MyView();
        view.Display();
    }

}