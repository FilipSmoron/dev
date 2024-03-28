class NewtonInterpolation:
    def __init__(self, nodes, values):
        self.nodes = nodes
        self.values = values
        self.coefficients = self.calculate_coefficients()

    def calculate_coefficients(self):
        coefficients = list(self.values)

        for j in range(1, len(self.nodes)):
            for i in range(len(self.nodes) - 1, j - 1, -1):
                coefficients[i] = (coefficients[i] - coefficients[i - 1]) / (self.nodes[i] - self.nodes[i - j])

        return coefficients

    def evaluate_polynomial(self, x):
        result = self.coefficients[-1]

        for i in range(len(self.nodes) - 2, -1, -1):
            result = self.coefficients[i] + result * (x - self.nodes[i])

        return result

if __name__ == "__main__":
    with open("dane1.txt", "r") as file:
        nodes_num = int(file.readline())
        nodes = []
        values = []

        for _ in range(nodes_num):
            node, value = map(float, file.readline().split())
            nodes.append(node)
            values.append(value)

    print("Liczba węzłów:", nodes_num)
    print("Dane: Węzły interpolacji i wartości funkcji w węzłach:")
    for i in range(nodes_num):
        print("Węzeł:", nodes[i], "Wartość:", values[i])

    x = float(input("Podaj punkt, w którym chcesz obliczyć wartość wielomianu: "))

    interpolation = NewtonInterpolation(nodes, values)

    print("Punkt, w którym liczymy wartość wielomianu:", x)
    print("Wartość wielomianu Newtona w danym punkcie:", interpolation.evaluate_polynomial(x))
    print("Współczynniki wielomianu Newtona (b_k):", interpolation.coefficients)
