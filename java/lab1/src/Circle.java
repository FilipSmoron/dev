public class Circle extends Figure implements Printable {
    private double r;

    public Circle(double r) {
        if (r <= 0) {
            throw new IllegalArgumentException("Invalid circle radius");
        }
        this.r = r;
    }

    @Override
    public double calculateArea() {
        return Math.PI * r * r;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * Math.PI * r;
    }

    public double getR() {
        return r;
    }

    @Override
    public void print() {
        System.out.printf("Circle: r = %.2f, area = %.2f, perimeter = %.2f\n", r, calculateArea(), calculatePerimeter());
    }
}
