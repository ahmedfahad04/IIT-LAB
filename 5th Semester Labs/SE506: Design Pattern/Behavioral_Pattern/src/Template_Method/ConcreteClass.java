package Template_Method;

class ConcreteClass extends AbstractClass {
    protected void doSomething() {
        System.out.println("Doing something");
    }

    protected void doSomethingElse() {
        System.out.println("Doing something else");
    }

    protected void doFinalStep() {
        System.out.println("Doing the final step");
    }

    // Override the hook method to include the [optional step]
    protected boolean hookMethod() {
        return true;
    }

    // Override the optional step to take something specific
    protected void doSomethingOptional() {
        System.out.println("Doing something optional");
    }
}
