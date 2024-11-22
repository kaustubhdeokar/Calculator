#include <iostream>
#include "operations.h"
#include "trig_operations.h"
#include "compound_interest.h"

int main()
{
    double num1, num2;
    char operation;

    double principal, rate;
    int times, years;

    std::cout << "Enter the principal amount: ";
    std::cin >> principal;
    std::cout << "Enter the annual interest rate (as a decimal): ";
    std::cin >> rate;
    std::cout << "Enter the number of times interest is compounded per year: ";
    std::cin >> times;
    std::cout << "Enter the number of years: ";
    std::cin >> years;

    double amount = calculateCompoundInterest(principal, rate, times, years);
    std::cout << "The compound interest amount is: " << amount << std::endl;

    /*    double angle;
        std::cout << "Enter an angle in radians: ";
        std::cin >> angle;

        std::cout << "sin(" << angle << ") = " << sincalc(angle) << std::endl;
        std::cout << "cos(" << angle << ") = " << coscalc(angle) << std::endl;
        std::cout << "tan(" << angle << ") = " << tancalc(angle) << std::endl;
    */
    /*
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter an operation (+, -, *, /): ";
        std::cin >> operation;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        try {
            double result;
            switch (operation) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    break;
                default:
                    std::cerr << "Invalid operation" << std::endl;
                    return 1;
            }
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    */

    return 0;
}