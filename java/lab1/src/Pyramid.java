public class Pyramid implements Printable{
    private Figure base;  // Typ abstrakcyjny Figure
    private double height;

    public Pyramid(Figure base, double height) {
        if (height <= 0) {
            throw new IllegalArgumentException("Height must be positive.");
        }
        this.base = base;
        this.height = height;
    }


    public double calculateSurfaceArea() {
        if (base instanceof Circle) {
            double slantHeight = Math.sqrt(Math.pow(((Circle) base).getR(), 2) + Math.pow(height, 2));
            return base.calculateArea() + ((Circle) base).calculatePerimeter() * slantHeight / 2;
        } else if (base instanceof Rectangle) {
            return ((Rectangle) base).getA() * (((Rectangle) base).getB()) + ((Rectangle) base).getA() * Math.sqrt(Math.pow((((Rectangle) base).getB()) / 2, 2) + Math.pow(height, 2)) + (((Rectangle) base).getB()) * Math.sqrt(Math.pow(((Rectangle) base).getA() / 2, 2) + Math.pow(height, 2));
        } else if (base instanceof Triangle) {
            double slantHeight = Math.sqrt(Math.pow(((Triangle) base).getA() / 2, 2) + Math.pow(height, 2));
            return base.calculateArea() + ((Triangle) base).calculatePerimeter() * slantHeight / 2;
        } else {
            throw new IllegalArgumentException("Unsupported base type.");
        }
    }

    public double calculateVolume() {
        return (1.0 / 3.0) * base.calculateArea() * height;
    }

    public void print() {
        System.out.println("Pyramid with base: " + base.getClass().getSimpleName());
        System.out.println("Height: " + height);
        if (!(base instanceof Triangle)) {
            System.out.println("Surface area: " + calculateSurfaceArea());
        } else {
            System.out.println("Base area: " + base.calculateArea());
        }
            System.out.println("Volume: " + calculateVolume());

    }
}
