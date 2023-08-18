package practice.strategy;

public class Movement {
    private Strategy movement;

    public Movement(Strategy movement) {
        this.movement = movement;
    }

    public void executeMovement(){
        movement.execute();
    }
}
