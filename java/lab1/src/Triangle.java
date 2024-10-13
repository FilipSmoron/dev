public class Triangle extends Figure implements Printable {
    private double a;
    private double b;
    private double c;

    public Triangle(double a, double b, double c) {
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw new IllegalArgumentException("Invalid triangle sides");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Triangle(double baseLength, double triangleHeight) {

    }

    @Override
    public double calculateArea() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    @Override
    public double calculatePerimeter() {
        return a + b + c;
    }

    @Override
    public void print() {
        System.out.printf("Triangle: a = %.2f, b =  %.2f, c = %.2f, area = %.2f, perimeter = %.2f\n", a, b, c, calculateArea(), calculatePerimeter());
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }
}
