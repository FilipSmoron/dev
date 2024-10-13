public class Rectangle extends Figure implements Printable {
    private double a;
    private double b;

    public Rectangle(double a, double b) {
        if (a <= 0 || b <= 0) {
            throw new IllegalArgumentException("Invalid rectangle sides");
        }
        this.a = a;
        this.b = b;
    }

    @Override
    public double calculateArea() {
        return a * b;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * (a + b);
    }

    @Override
    public void print() {
        System.out.printf("Rectangle: a = %.2f, b = %.2f, area = %.2f, perimeter = %.2f\n", a, b, calculateArea(), calculatePerimeter());
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }
}
