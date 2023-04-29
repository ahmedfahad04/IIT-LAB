package builder;

// package builder_pattern;

public class client {
    public static void main(String args[]){
        MazeGame game = new MazeGame();
        MazeBuilder countingbuilder = new CountingMazeBuilder();

        game.createMaze(countingbuilder);   // complex object is created by passing builder object
        countingbuilder.GetMaze();

        // mane soja banglay, 


        // builder pattern e 
        // jodi ami full maze take alada alada structure e sajate cai
        // tokhon ami new ekta maze builder banabo, zeta puro maze
        // er structure define kortesse
        // builder use kortesi,,,, karon ekta maze banate
        // wall, door, room etc. onek object create krte hoy
        // jeta ekta complex obj creation
        // pore client class e oi particular builder
        // ta pass kore maze create korte pari and
        // getMaze() method ta call kore maze er details nite pari


        // ar abstract factory te 
        // amra whole structure e hat dei na, oita same thake
        // just structure er element gulo change korte pari
        // through, oi element gulor je class/group/family thake
        // ogular subclass baniye method gulo override kori
        // pore client end e just oi particular factory subclass
        // ta pass kore amra specific door, room egula pai

        
        // ar factory te
        // almost same to abstract factory
        // just ekhane family wise implementation na kore
        // specific element gular subclass banai
        // and factory method ta override kori 
        // pore client end e just oi particular factory subclass
        // ta instantiate kore amra specific door, room egula pai
    }
}
