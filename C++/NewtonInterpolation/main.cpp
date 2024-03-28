#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class NewtonInterpolation {
private:
    vector<double> nodes;
    vector<double> values;
    vector<double> coefficients;

public:
    NewtonInterpolation(const vector<double>& nodes, const vector<double>& values):nodes(nodes), values(values) {
        calculate_coefficients();
    }

    void calculate_coefficients() {
        coefficients = values;

        for (int j = 1; j < nodes.size(); ++j) {
            for (int i = nodes.size() - 1; i >= j; --i) {
                coefficients[i] = (coefficients[i] - coefficients[i - 1]) / (nodes[i] - nodes[i - j]);
            }
        }
    }

    double evaluate_polynomial(double x) {
        double result = coefficients.back();

        for (int i = coefficients.size() - 2; i >= 0; --i) {
            result = result * (x - nodes[i]) + coefficients[i];
        }

        return result;
    }

    const vector<double>& get_coefficients() const {
        return coefficients;
    }
};

int main() {
    ifstream file("dane1.txt");
    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku dane1.txt" << endl;
        return 1;
    }

    int num_nodes;
    file >> num_nodes;

    vector<double> nodes(num_nodes);
    vector<double> values(num_nodes);

    for (int i = 0; i < num_nodes; ++i) {
        file >> nodes[i] >> values[i];
    }

    file.close();

    cout << "Liczba wezlow: " << num_nodes << endl;
    cout << "Dane: Wezly interpolacji i wartosci funkcji w wezlach:" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        cout << "Wezel: " << nodes[i] << " Wartosc: " << values[i] << endl;
    }

    double x;
    cout << "Podaj punkt, w ktorym chcesz obliczyc wartosc wielomianu: ";
    cin >> x;

    NewtonInterpolation interpolation(nodes, values);

    cout << "Punkt, w ktorym liczymy wartosc wielomianu: " << x << endl;
    cout << "Wartosc wielomianu Newtona w danym punkcie: " << interpolation.evaluate_polynomial(x) << endl;
    cout << "Wspolczynniki wielomianu Newtona (b_k): ";
    for (auto coefficient : interpolation.get_coefficients()) {
        cout << coefficient << " ";
    }
    cout << endl;

    return 0;
}
