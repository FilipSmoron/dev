#include <iostream>

using namespace std;

int main() {

    int a, b, c;
    cin >> a >> b >> c;
    int MaiorAB = (a + b + abs(a - b)) / 2;
    if (MaiorAB >= c) {
        cout << MaiorAB << " eh o maior" << endl;
    }
    else
        cout << c << " eh o maior" << endl;
    return 0;
}