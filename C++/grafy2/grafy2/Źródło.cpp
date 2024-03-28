#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <string>

using namespace std;

void print(vector<vector<double>> graph) {
	for (vector<double> x : graph) {
		for (double y : x) {
			cout << y << "\t";
		}
		cout << "\n\n\n\n";
	}
}

void connected(vector<vector<double>> graph) {
	int k = graph.size();
	for (int i = 0; i < k; i++) {
		cout << "\nv" << i << ":\t";
		for (int j = 0; j < k; j++) {
			if (graph[i][j] != 0) {
				cout << "v" << j << ", ";
			}
		}
	}

}

vector<vector<double>> load(string text) {
	vector<vector<double>> graph;
	ifstream file(text);
	if (file.is_open())
	{
		string line;
		while (getline(file, line)) {

			vector<double> wektor;
			string stringdodoubla = "";

			for (int i = 0; i <= line.length(); i++) {
				if ((line[i] != ';') && (i != line.length())) {
					stringdodoubla += line[i];
				}
				else {
					double doubla = stod(stringdodoubla);
					stringdodoubla = "";
					wektor.push_back(doubla);
				}
			}
			graph.push_back(wektor);
		}

	}
	else cout << "Unable to open file" << endl;
	return graph;
}

void road(vector<vector<double>> graph, vector<vector<double>> coords) {
	double min = 0;
	int k = graph.size();
	int w1 = 0;
	int w2 = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; i < k; i++) {
			if (graph[i][j] != 0) {
				double x = (coords[i][0] - coords[j][0]);
				double y = (coords[i][1] - coords[j][1]);
				double s = sqrt(pow(x, 2) + pow(y, 2));
				if ((s <= min) || (min == 0)) {
					min = s;
					w1 = i;
					w2 = j;
				}
			}
		}
	}
	cout << "\nWierzcholki: v" << w1 << " i v" << w2 << "\nodleglosc: " << min << endl;
}

void speed(vector<vector<double>> graph, vector<vector<double>> coords) {
	double min = 0;
	int k = graph.size();
	int w1;
	int w2;
	for (int i = 0; i < k; i++) {
		for (int j = 0; i < k; i++) {
			if (graph[i][j] != 0) {
				double x = (coords[i][0] - coords[j][0]);
				double y = (coords[i][1] - coords[j][1]);
				double s = (sqrt(pow(x, 2) + pow(y, 2)) / graph[i][j]);
				if (s <= min || min == 0) {
					min = s;
					w1 = i;
					w2 = j;
				}
			}
		}
	}

	cout << "\nNajwieksza szybkosc miedzy  wierzcholkami: v" << w1 << " i v" << w2 << "\n";
	cout << "\nO czasie: " << min << endl;
}

void main() {
	vector<vector<double>> graf;		//a
	graf = load("graph.csv");
	print(graf);

	cout << "\n------------------------------------\n";

	vector<vector<double>> koordynaty;		//a
	koordynaty = load("coordinates.csv");
	print(koordynaty);

	cout << "\n------------------------------------\n";

	connected(graf);		//b

	cout << "\n------------------------------------\n";

	road(graf, koordynaty);		//c

	cout << "\n------------------------------------\n";

	speed(graf, koordynaty);		//d
}
