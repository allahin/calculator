#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Fonksiyon prototipleri
double calculate(std::vector<double>& numbers, char op);

int main() {
    char choice;
    do {
        std::vector<double> numbers;
        char op;
        double num;
        std::string input;

        // Sayı girişi
        std::cout << "Enter a number: ";
        std::cin >> num;
        numbers.push_back(num);

        // İşlem ve sayı girişi devam ediyor mu?
        do {
            std::cout << "Enter an operation (+, -, *, /), 'done' to finish, or another number: ";
            std::cin >> input;

            if (input == "done") break;

            std::istringstream iss(input);
            if (iss >> num) {
                numbers.push_back(num);
            } else if (input.length() == 1) {
                op = input[0];
                double result = calculate(numbers, op);
                std::cout << "Intermediate result: " << result << std::endl;
                numbers.clear();
                numbers.push_back(result);
            } else {
                std::cout << "Invalid input!" << std::endl;
            }

        } while (true);

        // Son sonucu ekrana yazdır
        if (!numbers.empty()) {
            std::cout << "Final result: " << numbers[0] << std::endl;
        }

        // Devam edilsin mi?
        std::cout << "Do you want to perform another calculation? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "Exiting the program...\n";

    return 0;
}

// Hesaplama fonksiyonu
double calculate(std::vector<double>& numbers, char op) {
    double result = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        switch(op) {
            case '+':
                result += numbers[i];
                break;
            case '-':
                result -= numbers[i];
                break;
            case '*':
                result *= numbers[i];
                break;
            case '/':
                if (numbers[i] != 0)
                    result /= numbers[i];
                else {
                    std::cout << "Error! Division by zero!" << std::endl;
                    return 0;
                }
                break;
            default:
                std::cout << "Invalid operation!" << std::endl;
                return 0;
        }
    }
    return result;
}
