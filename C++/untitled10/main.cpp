#include <iostream>

template <typename T, typename R>
        class Kalkulator {
private:
    T x;
    R y;
public:
    T dodawanie(T x, R y) {
        return x + y;
    }
    T odejmowanie(T x, R y) {
        return x - y;
    }
    T mnozenie(T x, R y) {
        return x * y;
    }
    T dzielenie(T x, R y) {
        return x / y;
    }

};


int main() {

    Kalkulator<int, int> kalkulator1;
    std::cout << "Dzialania dla 3 i 8"<<std::endl;
    std::cout << kalkulator1.dodawanie(3, 8) << std::endl;
    std::cout << kalkulator1.odejmowanie(3, 8) << std::endl;
    std::cout << kalkulator1.mnozenie(3, 8) << std::endl;
    std::cout << kalkulator1.dzielenie(3, 8) << std::endl;
    Kalkulator<float, float> kalkulator2;
    std::cout << "Dzialania dla 2.53 float i 2.99 float" << std::endl;
    std::cout << kalkulator2.dodawanie(2.53f, 2.99f) << std::endl;
    std::cout << kalkulator2.odejmowanie(2.53f, 2.99f) << std::endl;
    std::cout << kalkulator2.mnozenie(2.53f, 2.99f) << std::endl;
    std::cout << kalkulator2.dzielenie(2.53f, 2.99f) << std::endl;
    Kalkulator<double, unsigned int> kalkulator3;
    std::cout << "Dzialania dla 5.22 double i 7 unsigned int" << std::endl;
    std::cout << kalkulator3.dodawanie(5.22, 7) << std::endl;
    std::cout << kalkulator3.odejmowanie(5.22, 7) << std::endl;
    std::cout << kalkulator3.mnozenie(5.22, 7) << std::endl;
    std::cout << kalkulator3.dzielenie(5.22, 7) << std::endl;


    return 0;
}
