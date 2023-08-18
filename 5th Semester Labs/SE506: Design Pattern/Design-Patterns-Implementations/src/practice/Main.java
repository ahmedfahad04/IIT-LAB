package practice;

import practice.Abstract.AbstractFactory;
import practice.Abstract.FactoryProducer;
import practice.singleton.Singleton;
import practice.strategy.Jump;
import practice.strategy.Movement;
import practice.strategy.Run;

public class Main {

    public static void main(String[] args) {
	// write your code here

        AbstractFactory gameFactory = FactoryProducer.getFactory("Game");

//        gameFactory.getGame("Valorant").play();
//        gameFactory.getGame("Fortnite").play();
////        gameFactory.getWeapon("Vandal").shoot();
//
//        AbstractFactory weaponFactory = FactoryProducer.getFactory("Weapon");
//
//        weaponFactory.getWeapon("Vandal").shoot();
//        weaponFactory.getWeapon("Phantom").shoot();


        Movement m1 = new Movement(new Jump());
        m1.executeMovement();

        Movement m2 = new Movement(new Run());
        m2.executeMovement();

//        new Jump().execute();
//        new Run().execute();

        Singleton s = Singleton.getInstance();
        s.show();


    }
}
