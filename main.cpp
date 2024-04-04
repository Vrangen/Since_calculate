#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        return a / b;
    }

    double modulus(double a, double b) {
        return fmod(a, b);
    }
};

int main() {
    Calculator calc;

    double a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter operator (+, -, *, /, %): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> b;

    try {
        double result;
        switch (op) {
        case '+':
            result = calc.add(a, b);
            break;
        case '-':
            result = calc.subtract(a, b);
            break;
        case '*':
            result = calc.multiply(a, b);
            break;
        case '/':
            result = calc.divide(a, b);
            break;
        case '%':
            result = calc.modulus(a, b);
            break;
        default:
            throw invalid_argument("Invalid operator");
        }
        cout << "Result: " << result << endl;
    }
    catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}