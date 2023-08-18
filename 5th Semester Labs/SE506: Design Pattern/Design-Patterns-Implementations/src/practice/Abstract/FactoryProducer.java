package practice.Abstract;

import practice.Abstract.Games.GameFactory;
import practice.Abstract.Weapon.WeaponFactory;

public class FactoryProducer {
    public static AbstractFactory getFactory(String factory){
        if(factory == null)
            return null;

        if(factory.equalsIgnoreCase("Weapon")){
            return new WeaponFactory();
        }else if(factory.equalsIgnoreCase("Game")){
            return new GameFactory();
        }

        return null;
    }
}
