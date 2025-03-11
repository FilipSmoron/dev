import math as mat
import numpy as np
from itertools import product


# parameters
class GlobalData:
    def __init__(self, parameters):
        self.parameters = parameters


# node position information
class Node:
    def __init__(self, node_id, x, y):
        self.node_id = node_id
        self.x = x
        self.y = y


# node IDs and integration point information
class Element:
    def __init__(self, element_id, node_ids, npc):
        self.element_id = element_id
        self.node_ids = node_ids
        self.npc = npc  # number of integration points


# grid class to hold nodes and elements
class Grid:
    def __init__(self, nodes, elements):
        self.nodes = nodes
        self.elements = elements


# element universal structure with shape functions and derivatives
class ElemUniv:
    def __init__(self, npc, pc_points=None):
        self.npc = npc
        self.pc_points = pc_points  # integration points
        self.shape_functions = self.compute_shape_functions()

    def compute_shape_functions(self):
        shape_functions = []
        for ksi, eta in self.pc_points:
            N = [
                0.25 * (1 - ksi) * (1 - eta),  # N1
                0.25 * (1 + ksi) * (1 - eta),  # N2
                0.25 * (1 + ksi) * (1 + eta),  # N3
                0.25 * (1 - ksi) * (1 + eta)  # N4
            ]
            shape_functions.append(N)
        return shape_functions

    def get_shape_function_derivatives(self, ksi, eta):
        # Derivatives: ksi and eta
        dN_dksi = [
            -0.25 * (1 - eta),  # dN1/dksi
            0.25 * (1 - eta),  # dN2/dksi
            0.25 * (1 + eta),  # dN3/dksi
            -0.25 * (1 + eta)  # dN4/dksi
        ]

        dN_deta = [
            -0.25 * (1 - ksi),  # dN1/deta
            -0.25 * (1 + ksi),  # dN2/deta
            0.25 * (1 + ksi),  # dN3/deta
            0.25 * (1 - ksi)  # dN4/deta
        ]

        return dN_dksi, dN_deta


# Jacobian class with matrix and determinant calculation
class Jakobian:
    def __init__(self):
        self.J = [[0.0] * 2 for _ in range(2)]  # 2x2 matrix
        self.detJ = 0.0

    def compute_jacobian(self, element, nodes, ksi, eta):
        x = [nodes[node_id - 1].x for node_id in element.node_ids]
        y = [nodes[node_id - 1].y for node_id in element.node_ids]

        elem_univ = ElemUniv(element.npc, [(ksi, eta)])

        dN_dksi, dN_deta = elem_univ.get_shape_function_derivatives(ksi, eta)

        dXdksi = sum(dN_dksi[i] * x[i] for i in range(4))
        dYdksi = sum(dN_dksi[i] * y[i] for i in range(4))

        dXdeta = sum(dN_deta[i] * x[i] for i in range(4))
        dYdeta = sum(dN_deta[i] * y[i] for i in range(4))

        # Jacobian matrix
        self.J[0][0] = dXdksi
        self.J[0][1] = dYdksi
        self.J[1][0] = dXdeta
        self.J[1][1] = dYdeta

        # Determinant of Jacobian
        self.detJ = self.J[0][0] * self.J[1][1] - self.J[0][1] * self.J[1][0]
        return dN_dksi, dN_deta  # derivatives: ksi and eta


# H matrix calculator class
class HMatrixCalculator:
    def __init__(self, k_value):
        self.k = k_value  # Thermal conductivity

    def calculate_H_matrix(self, element, nodes, pc_points, weights):
        H = [[0.0 for _ in range(4)] for _ in range(4)]  # Final 4x4 H matrix
        H_pc_matrices = []  # individual H matrices for each integration point

        for i, (ksi, eta) in enumerate(pc_points):
            # Compute Jacobian and derivatives for current Gauss point
            jakobian = Jakobian()
            dN_dksi, dN_deta = jakobian.compute_jacobian(element, nodes, ksi, eta)

            # Compute inverse Jacobian matrix for coordinate transformation
            invJ = [[jakobian.J[1][1] / jakobian.detJ, -jakobian.J[0][1] / jakobian.detJ],
                    [-jakobian.J[1][0] / jakobian.detJ, jakobian.J[0][0] / jakobian.detJ]]

            # Transformation of derivatives from natural coordinates to global coordinates
            dN_dx = [invJ[0][0] * dN_dksi[j] + invJ[0][1] * dN_deta[j] for j in range(4)]
            dN_dy = [invJ[1][0] * dN_dksi[j] + invJ[1][1] * dN_deta[j] for j in range(4)]

            # Calculate local H matrix at this integration point
            H_i = [[0.0 for _ in range(4)] for _ in range(4)]
            for m in range(4):
                for n in range(4):
                    H_i[m][n] = (
                        dN_dx[m] * dN_dx[n] +
                        dN_dy[m] * dN_dy[n]
                    ) * self.k * jakobian.detJ * weights[i][0] * weights[i][1]

            # Add the local H matrix to the global H matrix
            for m in range(4):
                for n in range(4):
                    H[m][n] += H_i[m][n]

            # Save individual H matrices for debugging or future use
            H_pc_matrices.append(H_i)

        return H, H_pc_matrices

# load data from file
def loadData(file):
    parameters = {}
    nodes = []
    elements = []
    boundary_conditions = []
    section = None

    with open(file, 'r') as f:
        for line in f:
            line = line.strip()

            if line.startswith("*Node"):
                section = "nodes"
                continue
            elif line.startswith("*Element"):
                section = "elements"
                continue
            elif line.startswith("*BC"):
                section = "boundary_conditions"
                continue

            if section is None:
                # General parameters
                if line:
                    x = line.split()
                    key = " ".join(x[:-1])
                    value = float(x[-1])
                    parameters[key] = value
            elif section == "nodes":
                # Node values
                node_data = line.split(',')
                node_id = int(node_data[0])
                x, y = float(node_data[1]), float(node_data[2])
                nodes.append(Node(node_id, x, y))
            elif section == "elements":
                # Element indices
                element_data = [int(x) for x in line.split(',')]
                element_id = element_data[0]
                node_ids = element_data[1:]
                npc = 4 # domyślnie 4 punkty
                elements.append(Element(element_id, node_ids, npc))
            elif section == "boundary_conditions":
                # Boundary conditions
                boundary_conditions.extend([int(x) for x in line.split(',')])

    return GlobalData(parameters), nodes, elements, boundary_conditions

# C matrix calculator class
class CMatrixCalculator:
    def __init__(self, rho, specific_heat):
        self.rho = rho  # Material density
        self.c = specific_heat  # Specific heat

    def calculate_C_matrix(self, element, nodes, pc_points, weights):
        C = [[0.0 for _ in range(4)] for _ in range(4)]  # Initialize 4x4 local C matrix

        for i, (ksi, eta) in enumerate(pc_points):
            # Compute Jacobian for this Gauss point
            jakobian = Jakobian()
            jakobian.compute_jacobian(element, nodes, ksi, eta)

            # Shape functions at this Gauss point
            elem_univ = ElemUniv(element.npc, [(ksi, eta)])
            N = elem_univ.shape_functions[0]  # Shape functions at (ksi, eta)

            # Calculate local C matrix contribution at this Gauss point
            weight_x, weight_y = weights[i]  # Gauss weights
            detJ = jakobian.detJ

            for m in range(4):
                for n in range(4):
                    C[m][n] += (
                        self.rho * self.c * N[m] * N[n] * detJ * weight_x * weight_y
                    )

        return C # return the local C matrix

# H_bc matrix calculator class
class HbcCalculator:
    def __init__(self, alpha, tot):
        self.alpha = alpha # heat transfer coefficient
        self.tot = tot # ambient temperature

    def calculate_Hbc_and_p(self, element, nodes, boundary_conditions):
        H_bc = [[0.0 for _ in range(4)] for _ in range(4)]  # initialize the boundary H matrix
        p_local = [0.0 for _ in range(4)]  # initialize the local p vector

        # Edges of the element: (0,1), (1,2), (2,3), (3,0)
        edges = [(0, 1), (1, 2), (2, 3), (3, 0)]

        for edge in edges:
            # Check if both nodes are on the boundary
            id_1, id_2 = element.node_ids[edge[0]], element.node_ids[edge[1]]  # global node IDs
            if {id_1, id_2} <= set(boundary_conditions):  # Both nodes must be on the boundary
                node1, node2 = nodes[id_1 - 1], nodes[id_2 - 1] # node indices start from 1

                # edge length
                edge_length = mat.sqrt((node2.x - node1.x)**2 + (node2.y - node1.y)**2)

                gauss_points = [-1/mat.sqrt(3), 1/mat.sqrt(3)]
                weights = [1.0, 1.0]  # for 2-point quadrature

                # gauss_points =[-mat.sqrt(3/5), 0, mat.sqrt(3/5)]
                # weights = [5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0]; # for 3-point quadrature

                for gauss_points, weights in zip(gauss_points, weights):
                    N = self.shape_functions(gauss_points)

                    # Local H_bc matrix for the edge
                    for i in range(len(N)):  # Local node i on the edge
                        for j in range(len(N)):  # Local node j on the edge
                            global_i = edge[i]  # global index
                            global_j = edge[j]  # global index
                            H_bc[global_i][global_j] += (
                                    self.alpha * edge_length / 2.0 * N[i] * N[j] * weights
                            )
                        p_local[edge[i]] += self.alpha * self.tot * N[i] * edge_length / 2.0 * weights

        return H_bc, p_local # return the boundary H matrix and local p vector

    def shape_functions(self, gauss_points):
        # Shape functions for 1D
        return [
            0.5 * (1 - gauss_points),  # N1 = 0.5 * (1 - ksi)
            0.5 * (1 + gauss_points)   # N2 = 0.5 * (1 + ksi)
        ]

# Gauss elimination class
class GaussElimination:
    def __init__(self, matrix):
        self.matrix = matrix

    def forward_elimination(self):
        n = len(self.matrix)

        for i in range(n):
            if self.matrix[i][i] == 0:
                print("Wystąpiło 0 na przekątnej macierzy. Metoda Gaussa nie może być zastosowana.")
                return False

            for j in range(i + 1, n):
                ratio = self.matrix[j][i] / self.matrix[i][i]

                for k in range(n + 1):
                    self.matrix[j][k] = self.matrix[j][k] - ratio * self.matrix[i][k]

        return True

    def back_substitution(self):
        n = len(self.matrix)
        x = [0] * n

        for i in range(n - 1, -1, -1):
            x[i] = self.matrix[i][n] / self.matrix[i][i]

            for j in range(i - 1, -1, -1):
                self.matrix[j][n] -= self.matrix[j][i] * x[i]

        return x

    def print_matrix(self):
        for row in self.matrix:
            print(row)


# # Example nodes and elements - przykład testowy 2
# nodes_example = [
#     Node(1, 0.01, -0.01),
#     Node(2, 0.025, 0.0),
#     Node(3, 0.025, 0.025),
#     Node(4, 0.0, 0.025)
# ]
#
# elements_example = [
#     Element(1, [1, 2, 3, 4], npc=4) #npc = 9 for 3x3, npc = 4 for 2x2
# ]

# Function to generate Gauss points and weights for integration

# Function to generate Gauss points and weights for integration
def generate_gauss_points(npc):
    points, weights = np.polynomial.legendre.leggauss(int(npc))
    pc_points = list(product(points, repeat=2))
    weights = list(product(weights, repeat=2))
    return pc_points, weights

class SolveOfEquation:
    def __init__(self, num_nodes):
        # global matrix H with zeros
        self.global_H = [[0.0 for _ in range(num_nodes)] for _ in range(num_nodes)]
        self.global_p = [0.0 for _ in range(num_nodes)]
        self.global_C = [[0.0 for _ in range(num_nodes)] for _ in range(num_nodes)]

    def add_local_H_and_C_and_p(self, local_H, local_C, local_p, element, global_node_ids):
        # Map local nodes to global nodes
        for i_local, i_global in enumerate(global_node_ids):
            for j_local, j_global in enumerate(global_node_ids):
                self.global_H[i_global - 1][j_global - 1] += local_H[i_local][j_local]
                self.global_C[i_global - 1][j_global - 1] += local_C[i_local][j_local]
            self.global_p[i_global - 1] += local_p[i_local]

    def print_global_H_and_p(self):
        print("Global H matrix:")
        for row in self.global_H:
            print(" ".join([f"{val:.5f}" for val in row]))
        print("\nGlobal p vector:")
        print(" ".join([f"{val:.5f}" for val in self.global_p]))


def main(file_path):
    global_data, nodes, elements, boundary_conditions = loadData(file_path)

    # Initialize the solver with the number of nodes
    num_nodes = len(nodes)
    solver = SolveOfEquation(num_nodes)

    print("Global parameters:")
    print(global_data.parameters)
    print("\nNodes:")
    for node in nodes:
        print(f"Node ID: {node.node_id}, X: {node.x}, Y: {node.y}")
    print("\nElements:")
    for element in elements:
        print(f"Element ID: {element.element_id}, Node IDs: {element.node_ids}")
    print("\nBoundary conditions:")
    print(boundary_conditions)


    for element in elements:
        npc = element.npc
        pc_points, weights = generate_gauss_points(npc)
        elem_univ = ElemUniv(npc, pc_points)

        # Compute the local H matrix
        h_calculator = HMatrixCalculator(global_data.parameters['Conductivity'])
        H, H_pc_matrices = h_calculator.calculate_H_matrix(element, nodes, pc_points, weights)

        hbc_calculator = HbcCalculator(global_data.parameters['Alfa'], global_data.parameters['Tot'])
        H_bc, p_local = hbc_calculator.calculate_Hbc_and_p(element, nodes, boundary_conditions)

        c_calculator = CMatrixCalculator(global_data.parameters['Density'], global_data.parameters['SpecificHeat'])
        C_local = c_calculator.calculate_C_matrix(element, nodes, pc_points, weights)


        # print local H matrix
        print("________________________________________________________")
        print(f"Element ID: {element.element_id}")
        print("________________________________________________________\n")
        print("Local H matrix:")
        print(np.array(H))
        print("\n")
        # Print local C matrix
        print("Local C matrix:")
        print(np.array(C_local))
        print("\n")

        #print local p vector
        print("Local p vector:")
        print(np.array(p_local))
        print("\n")


        # Add the boundary condition matrix to the local H matrix
        for i in range(4):
            for j in range(4):
                H[i][j] += H_bc[i][j]


        # Add the updated local H matrix to the global matrix
        global_node_ids = element.node_ids
        solver.add_local_H_and_C_and_p(H, C_local, p_local, element, global_node_ids)

        # print the H matrices
        print("Local H matrix (after adding H_bc):")
        print(np.array(H))
        print("\n")
        print("Individual H matrices for each integration point:")
        for idx, H_pc in enumerate(H_pc_matrices):
            print(f"[H]pc_{idx + 1}:")
            print(np.array(H_pc))
        print("\n")
        print("Boundary condition matrix H_bc:")
        print(np.array(H_bc))
        print("\n")

    # Print the global H matrix and p
    solver.print_global_H_and_p()
    print("\nGlobal C matrix:")
    for row in solver.global_C:
        print(" ".join([f"{val:.5f}" for val in row]))

    # Initialize temperature vector with InitialTemp
    temp_vector = [global_data.parameters['InitialTemp'] for _ in range(num_nodes)]

    # Simulation parameters
    simulation_time = global_data.parameters['SimulationTime']
    step_time = global_data.parameters['SimulationStepTime']
    num_steps = int(simulation_time / step_time)

    # Time stepping
    for step in range(0, num_steps):
        print(f"Step {step}/{num_steps}")

        # Calculate [H] + [C]/Δt
        H_plus_C_dt = [[solver.global_H[i][j] + solver.global_C[i][j] / step_time for j in range(num_nodes)] for i in
                       range(num_nodes)]

        # Calculate [C]/Δt * {T}
        C_dt_T = [sum(solver.global_C[i][j] / step_time * temp_vector[j] for j in range(num_nodes)) for i in
                  range(num_nodes)]

        # Calculate p: {p} + [C]/Δt * {T}
        rp = [solver.global_p[i] + C_dt_T[i] for i in range(num_nodes)]

        # # matrix for Gauss elimination
        # augmented_matrix = [H_plus_C_dt[i] + [rp[i]] for i in range(num_nodes)]
        #
        # # Solve using Gauss elimination
        # gauss = GaussElimination(augmented_matrix)
        #
        # if gauss.forward_elimination():
        #     solution = gauss.back_substitution()
        #     temp_vector = solution  # Update temperatures for the next step
        #
        #     print(f"Temperatures at step {step}:")
        #     print(" ".join([f"{val:.5f}" for val in temp_vector]))
        #
        # else:
        #     print("Error in solving the system. Simulation aborted.")
        #     break

        # Solution using numpy - quicker than Gauss elimination
        temp_vector = np.linalg.solve(H_plus_C_dt, rp)
        print(f"Temperatures at step {step}:")
        print(" ".join([f"{val:.5f}" for val in temp_vector]))

        # min and max temperature
        print(f"Min temperature: {min(temp_vector):.15f}")
        print(f"Max temperature: {max(temp_vector):.15f}")
        print("\n")

    ## Testowanie jakobiana itd
    # print("\nTest:")
    # for element in elements:
    #     for ksi, eta in pc_points:
    #         jakobian = Jakobian()
    #         print("\n__________________________________\n")
    #         print("Element ID:", element.element_id)
    #         print("__________________________________\n")
    #         print("Jakobian Matrix:")
    #         dN_dksi, dN_deta = jakobian.compute_jacobian(element, nodes, ksi, eta)
    #         print(np.array(jakobian.J))
    #         print("\n")
    #         print("Det(J):", jakobian.detJ)
    #         print("\n")
    #         print("\n")
    #         print("Shape functions:")
    #         print(np.array(elem_univ.shape_functions))
    #         print("\n")
    #         print("Shape function derivatives:")
    #         print(np.array(elem_univ.get_shape_function_derivatives(ksi, eta)))

file_path = 'Test3_31_31_kwadrat.txt'
main(file_path)