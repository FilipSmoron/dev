class GaussElimination:
    def __init__(self, matrix):
        self.matrix = matrix

    def forward_elimination(self):
        n = len(self.matrix)

        for i in range(n):
            if self.matrix[i][i] == 0:
                print("Wystąpiło 0 na przekątnej macierzy. Metoda Gaussa nie może być zastosowana.")
                return False

            for j in range(i+1, n):
                ratio = self.matrix[j][i] / self.matrix[i][i]

                for k in range(n+1):
                    self.matrix[j][k] = self.matrix[j][k] - ratio * self.matrix[i][k]

        return True

    def back_substitution(self):
        n = len(self.matrix)
        x = [0] * n

        for i in range(n-1, -1, -1):
            x[i] = self.matrix[i][n] / self.matrix[i][i]

            for j in range(i-1, -1, -1):
                self.matrix[j][n] -= self.matrix[j][i] * x[i]

        return x

    def print_matrix(self):
        for row in self.matrix:
            print(row)

if __name__ == "__main__":
    with open("dane2.txt", "r") as file:
        n = int(file.readline())
        matrix = []

        for _ in range(n):
            row = list(map(float, file.readline().split()))
            matrix.append(row)

    print("Macierz rozszerzona (przed obliczeniami):")
    for row in matrix:
        print(row)

    gauss = GaussElimination(matrix)

    if gauss.forward_elimination():
        print("\nMacierz rozszerzona (po pierwszym etapie obliczeń – postępowanie proste):")
        gauss.print_matrix()

        solution = gauss.back_substitution()

        print("\nRozwiązanie układu równań (x0 - xn):")
        for i in range(n):
            print(f"x{[i]} = {round(solution[i], 2)}")
