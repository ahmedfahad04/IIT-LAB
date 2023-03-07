package Template_Method;

/*

In the Template Method pattern, a "hook" is a method declared in the abstract base class, but only given an empty or default implementation. Subclasses may choose to override the hook method to provide additional behavior, but it is not required.

Here's an example of the Template Method pattern in Java that includes a hook:

*/
abstract class AbstractClass {

    // This is the template method that defines the overall algorithm
    public final void templateMethod() {
        // Step 1: Do something
        doSomething();

        // Step 2: Do something else
        doSomethingElse();

        // This is the hook method
        if (hookMethod()) {
            // Step 3: Do something optional
            doSomethingOptional();
        }

        // Step 4: Do the final step
        doFinalStep();
    }

    // these all are primitive operations
    // as their implementation is left for the subclasses
    protected abstract void doSomething();
    protected abstract void doSomethingElse();
    protected abstract void doFinalStep();

    // This is the hook method, which has a default implementation
    protected boolean hookMethod() {
        return false;
    }

    // This is an optional step that subclasses can override
    protected void doSomethingOptional() {
        // Default implementation does nothing
    }
}


/*
In this example, `AbstractClass` is an abstract base class that defines the template method `templateMethod()`, which is the algorithm that subclasses must implement. The method consists of several steps, some of which are required (`doSomething()`, `doSomethingElse()`, and `doFinalStep()`), and one of which is optional (`doSomethingOptional()`).

The `hookMethod()` is a method that has a default implementation but can be overridden by subclasses. In this example, `hookMethod()` is used to determine whether or not to execute the optional step (`doSomethingOptional()`).

The `ConcreteClass` subclass of `AbstractClass` provides implementations for the required methods (`doSomething()`, `doSomethingElse()`, and `doFinalStep()`), as well as the optional methods (`hookMethod()` and `doSomethingOptional()`). In this case, the `hookMethod()` returns `true`, which means that the optional step will be executed, and the `doSomethingOptional()` method is overridden to print a message.

When the `templateMethod()` is called on a `ConcreteClass` object, it will execute the algorithm in the expected order, including the optional step if the hook method returns `true`.
*/