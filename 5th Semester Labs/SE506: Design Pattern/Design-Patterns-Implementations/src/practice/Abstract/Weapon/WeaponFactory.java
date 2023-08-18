package practice.Abstract.Weapon;

import practice.Abstract.AbstractFactory;
import practice.Abstract.Games.Game;

public class WeaponFactory extends AbstractFactory {
    @Override
    public Weapon getWeapon(String weapon) {
        if(weapon == null)
            return null;

        if(weapon.equalsIgnoreCase("Phantom")){
            return new Phantom();
        }else if(weapon.equalsIgnoreCase("Vandal")){
            return new Vandal();
        }else if(weapon.equalsIgnoreCase("Spectre"))
            return new Spectre();
        return null;
    }

    @Override
    public Game getGame(String game) {
        return null;
    }
}
