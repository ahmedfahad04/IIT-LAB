package Mediator_Pattern_2;

// Define the Mediator interface
interface Mediator {
    void sendMessage(String message, Colleague colleague);
}

// Define the Colleague interface
interface Colleague {
    void receiveMessage(String message);
}

// Implement the Mediator interface
class ConcreteMediator implements Mediator {
    private Colleague colleague1;
    private Colleague colleague2;

    public void setColleague1(Colleague colleague) {
        this.colleague1 = colleague;
    }

    public void setColleague2(Colleague colleague) {
        this.colleague2 = colleague;
    }

    public void sendMessage(String message, Colleague colleague) {
        if(colleague == colleague1) {
            colleague2.receiveMessage(message);
        } else {
            colleague1.receiveMessage(message);
        }
    }
}

// Implement the Colleague interface
class ConcreteColleague1 implements Colleague {
    private Mediator mediator;

    public ConcreteColleague1(Mediator mediator) {
        this.mediator = mediator;
    }

    public void sendMessage(String message) {
        mediator.sendMessage(message, this);
    }

    public void receiveMessage(String message) {
        System.out.println("Colleague 1 received message: " + message);
    }
}

// Implement another Colleague
class ConcreteColleague2 implements Colleague {
    private Mediator mediator;

    public ConcreteColleague2(Mediator mediator) {
        this.mediator = mediator;
    }

    public void sendMessage(String message) {
        mediator.sendMessage(message, this);
    }

    public void receiveMessage(String message) {
        System.out.println("Colleague 2 received message: " + message);
    }
}

// Use the Mediator pattern
public class Main {
    public static void main(String[] args) {
        ConcreteMediator mediator = new ConcreteMediator();

        ConcreteColleague1 colleague1 = new ConcreteColleague1(mediator);
        ConcreteColleague2 colleague2 = new ConcreteColleague2(mediator);

        mediator.setColleague1(colleague1);
        mediator.setColleague2(colleague2);

        colleague1.sendMessage("Hello, colleague 2!");
        colleague2.sendMessage("Hi, colleague 1!");
    }
}
