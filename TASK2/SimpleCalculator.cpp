#include <iostream>
using namespace std;
class SimpleCalculator {
public:
    // Function to add two numbers
    double add(double a, double b) {
        return a + b;
    }

    // Function to subtract two numbers
    double subtract(double a, double b) {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Function to divide two numbers
    double divide(double a, double b) {
        if (b == 0) {
            cerr << "Error: Division by zero!" << endl;
            return 0; // Return 0 or handle error as needed
        }
        return a / b;
    }
};
int main() {
    SimpleCalculator calculator;
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;

    double result;
    switch (operation) {
        case '+':
            result = calculator.add(num1, num2);
            break;
        case '-':
            result = calculator.subtract(num1, num2);
            break;
        case '*':
            result = calculator.multiply(num1, num2);
            break;
        case '/':
            result = calculator.divide(num1, num2);
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}