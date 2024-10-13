import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Choose a shape: ");
            System.out.println("1. Triangle");
            System.out.println("2. Rectangle");
            System.out.println("3. Circle");
            System.out.println("4. Pyramid");
            System.out.println("5. Exit");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter sides a, b, c:");
                    Triangle triangle = new Triangle(scanner.nextDouble(), scanner.nextDouble(), scanner.nextDouble());
                    triangle.print();
                    break;
                case 2:
                    System.out.println("Enter width and height:");
                    Rectangle rectangle = new Rectangle(scanner.nextDouble(), scanner.nextDouble());
                    rectangle.print();
                    break;
                case 3:
                    System.out.println("Enter radius:");
                    Circle circle = new Circle(scanner.nextDouble());
                    circle.print();
                    break;
                case 4:
                    System.out.println("Choose base shape (1: Triangle, 2: Rectangle, 3: Circle):");
                    int baseChoice = scanner.nextInt();
                    Figure base = null;
                    switch (baseChoice) {
                        case 1:
                            System.out.println("Enter sides a, b, c:");
                            base = new Triangle(scanner.nextDouble(), scanner.nextDouble(), scanner.nextDouble());
                            break;
                        case 2:
                            System.out.println("Enter width and height:");
                            base = new Rectangle(scanner.nextDouble(), scanner.nextDouble());
                            break;
                        case 3:
                            System.out.println("Enter radius:");
                            base = new Circle(scanner.nextDouble());
                            break;
                    }
                    if (base != null) {
                        System.out.println("Enter height of the pyramid:");
                        Pyramid pyramid = new Pyramid(base, scanner.nextDouble());
                        pyramid.print();
                    }
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
