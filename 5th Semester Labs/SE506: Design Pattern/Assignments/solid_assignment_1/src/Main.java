//  Explanation:  We need to make interface because the relation between rectangle might be an 'is-a'
//  relation for Square, but they are not actually an "is substitution of" relation between them.
//  We could call them replaceable when both of them have same methods or behaviors, but here,
//  we observe a contrast in case of their height, width.
//
//  Therefore, we should create an abstraction for the behaviors that are common and expected to
//  contain each of its implementation. That's why we have added the common functionality in
//  an Interface and other's functionalities are class specific.
//
//  Thus using Interface, we can resolve the LSP Violation.


public class Main {
    public static void main(String[] args) {

        Rectangle rectangle = new Rectangle(10, 20);
        Square square = new Square(20);

        Shape recShape = new Rectangle(2,2);
        Shape squareShape = new Square(5);
        
        AreaCalculator areaCalculator = new AreaCalculator();

        rectangle.setSize(10, 25);
        square.setSize(25);

        areaCalculator.calculateArea(rectangle);
        areaCalculator.calculateArea(square);

        System.out.println(recShape.calculateArea());
        System.out.println(squareShape.calculateArea());

        // We can't change the size of each shape through recShape/squareShape because
        // size property is specific for each kind of Shape, it's not same for all.
        // However, we can relate a Rhombus with Square, Parallelogram with Rectangle
        // as in terms of SIZE, these pairs are similar/substitutable but Square &
        // Rectangle aren't.

    }
}
