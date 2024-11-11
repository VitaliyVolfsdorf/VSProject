#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string convertBase(string number, int baseFrom, int baseTo) {
    if (baseFrom < 2 || baseFrom > 32 || baseTo < 2 || baseTo > 32) {
        return "Ошибка: Основание системы счисления должно быть в диапазоне от 2 до 32.";
    }

    // Преобразование в десятичную систему
    int decimalNumber = 0;
    for (int i = 0; i < number.length(); i++) {
        int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : number[i] - 'A' + 10;
        decimalNumber += digit * pow(baseFrom, number.length() - i - 1);
    }

    // Преобразование из десятичной системы
    string convertedNumber = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % baseTo;
        char digit = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
        convertedNumber = digit + convertedNumber;
        decimalNumber /= baseTo;
    }
    return convertedNumber;
}

int main() {
    string number1, number2;
    int baseFrom1, baseFrom2, baseTo, operation;

    cout << "Введите первое число: ";
    cin >> number1;

    cout << "Введите систему счисления первого числа (от 2 до 32): ";
    cin >> baseFrom1;

    cout << "Введите второе число: ";
    cin >> number2;

    cout << "Введите систему счисления второго числа (от 2 до 32): ";
    cin >> baseFrom2;

    cout << "Введите целевую систему счисления (от 2 до 32): ";
    cin >> baseTo;

    cout << "Выберите операцию:\n";
    cout << "1 - Сложение\n";
    cout << "2 - Вычитание\n";
    cout << "3 - Умножение\n";
    cout << "4 - Деление\n";
    cout << "Введите номер операции: ";
    cin >> operation;

    // Преобразование чисел в десятичную систему
    int decimalNumber1 = stoi(convertBase(number1, baseFrom1, 10));
    int decimalNumber2 = stoi(convertBase(number2, baseFrom2, 10));

    int result;

    switch (operation) {
        case 1:
            result = decimalNumber1 + decimalNumber2;
            break;
        case 2:
            result = decimalNumber1 - decimalNumber2;
            break;
        case 3:
            result = decimalNumber1 * decimalNumber2;
            break;
        case 4:
            if (decimalNumber2 == 0) {
                cout << "Деление на ноль недопустимо!\n";
                return 1; 
            }
            result = decimalNumber1 / decimalNumber2;
            break;
        default:
            cout << "Некорректный номер операции!\n";
            return 1;
    }

    string convertedResult = convertBase(to_string(result), 10, baseTo);
    cout << "Результат: " << convertedResult << " в системе счисления " << baseTo << endl;

    return 0;
}
