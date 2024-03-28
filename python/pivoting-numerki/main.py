def partial_pivot(A, B):
    n = len(A)
    # Eliminacja Gaussa z wyborem częściowym
    for i in range(n):
        # Szukanie maksymalnego elementu w kolumnie i
        max_row = i
        for k in range(i+1, n):
            if abs(A[k][i]) > abs(A[max_row][i]):
                max_row = k
        # Zamiana wierszy
        A[i], A[max_row] = A[max_row], A[i]
        B[i], B[max_row] = B[max_row], B[i]
        # Eliminacja współczynników
        for k in range(i+1, n):
            factor = A[k][i] / A[i][i]
            B[k] -= factor * B[i]
            for j in range(i, n):
                A[k][j] -= factor * A[i][j]
    return A, B

def back_substitution(A, B):
    n = len(A)
    X = [0] * n
    # Rozwiązanie równań z wykorzystaniem wstecznej substytucji
    for i in range(n - 1, -1, -1):
        X[i] = (B[i] - sum(A[i][j] * X[j] for j in range(i+1, n))) / A[i][i]
    return X

def solve_linear_system(A, B):
    A, B = partial_pivot(A, B)
    X = back_substitution(A, B)
    return X

# Wczytanie danych z plików A3.txt i B3.txt
def read_matrices(file_A, file_B):
    with open(file_A) as f:
        A = [[float(x) for x in line.split()] for line in f]
    with open(file_B) as f:
        B = [float(x) for x in f]
    return A, B

# Rozwiązanie układu równań
def main():
    A, B = read_matrices("A3.txt", "B3.txt")
    print("Macierz A:")
    for row in A:
        print(row)
    print("\nMacierz B:")
    print(B)
    print("\nRozwiązanie układu równań:")
    X = solve_linear_system(A, B)
    print(X)

if __name__ == "__main__":
    main()

#
# def partial_pivot_gauss_crout(A, B):
#     n = len(A)
#     column_order = list(range(n))  # Inicjalizacja listy przechowującej kolejność kolumn
#
#     # Eliminacja Gaussa-Crouta z wyborem częściowym
#     for i in range(n):
#         # Znajdowanie indeksu wiersza z maksymalną wartością w kolumnie i
#         max_row = max(range(i, n), key=lambda k: abs(A[k][i]))
#
#         # Zamiana wierszy w macierzy A i wektorze B
#         A[i], A[max_row] = A[max_row], A[i]
#         B[i], B[max_row] = B[max_row], B[i]
#
#         # Zamiana kolumn w macierzy A
#         for row in A:
#             row[i], row[max_row] = row[max_row], row[i]
#
#         # Zaktualizowanie kolejności kolumn
#         column_order[i], column_order[max_row] = column_order[max_row], column_order[i]
#
#         # Eliminacja współczynników
#         for k in range(i + 1, n):
#             factor = A[k][i] / A[i][i]
#             for j in range(i, n):
#                 A[k][j] -= factor * A[i][j]
#             B[k] -= factor * B[i]
#
#     return A, B, column_order
#
# def back_substitution(A, B):
#     n = len(A)
#     X = [0] * n
#
#     # Rozwiązanie równań za pomocą substytucji wstecznej
#     for i in range(n - 1, -1, -1):
#         X[i] = (B[i] - sum(A[i][j] * X[j] for j in range(i + 1, n))) / A[i][i]
#
#     return X
#
# def solve_linear_system(A, B):
#     A, B, column_order = partial_pivot_gauss_crout(A, B)
#     X = back_substitution(A, B)
#     return X, column_order
#
# # Funkcja do wczytywania macierzy z pliku
# def read_matrix_from_file(filename):
#     with open(filename, 'r') as file:
#         lines = file.readlines()
#         matrix = [[float(value) for value in line.split()] for line in lines]
#     return matrix
#
# # Funkcja do wczytywania wektora z pliku
# def read_vector_from_file(filename):
#     with open(filename, 'r') as file:
#         vector = [float(value) for value in file.readlines()]
#     return vector
#
# # Funkcja do wypisywania macierzy
# def print_matrix(matrix):
#     for row in matrix:
#         print(row)
#
# # Funkcja do wypisywania wektora
# def print_vector(vector):
#     print(vector)
#
# # Rozwiązanie układu równań
# def main():
#     # Wczytanie macierzy rozszerzonej A z pliku
#     A = read_matrix_from_file("A3.txt")
#     # Wczytanie wektora B z pliku
#     B = read_vector_from_file("B3.txt")
#
#     # Wypisanie macierzy przed obliczeniami
#     print("Macierz rozszerzona A (przed obliczeniami):")
#     print_matrix(A)
#
#     # Wypisanie macierzy rozszerzonej po pierwszym etapie obliczeń (eliminacja Gaussa-Crouta)
#     A_copy = [row[:] for row in A]  # Skopiowanie macierzy A
#     B_copy = B[:]  # Skopiowanie wektora B
#     _, _, column_order = partial_pivot_gauss_crout(A_copy, B_copy)
#     print("\nMacierz rozszerzona A (po pierwszym etapie obliczeń):")
#     print_matrix(A_copy)
#
#     # Wypisanie wektora przechowującego informację o numerach kolumn
#     print("\nWektor przechowujący informację o numerach kolumn:")
#     print_vector(column_order)
#
#     # Rozwiązanie układu równań
#     solution, _ = solve_linear_system(A, B)
#
#     # Wypisanie rozwiązania układu równań
#     print("\nRozwiązanie układu równań (x0 - xn):")
#     print_vector(solution)
#
# if __name__ == "__main__":
#     main()