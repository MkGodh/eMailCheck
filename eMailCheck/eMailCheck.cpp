#include <iostream>
#include <string>
#include <istream>
#include <algorithm>

using namespace std;

bool firstPart(bool& correct, string eMail, string result, int& atIndex)
{
    int length = eMail.length();                    // Проверка строки на длинну
    bool foundAtsign = false;                       //Переменная для отслежки @

    if (length < 1 || length > 64) {
        correct = false;
    }

    for (int i = 0; i < eMail.length(); i++) {
        if (eMail[0] == '.') {                    // если первый символ равен точке - то мы выходим из цикла.
            correct = false;
            break;
        }

        if (eMail[i] == '@') {                  // если находим @ то прерываем цикл и переходим к след. функции.
            foundAtsign = true;
            correct = true;
            atIndex = i;
            break;
        }
        if (eMail[i] == '.' && eMail[i + 1] == '.') {
            correct = false;
            break;
        }

        if (eMail[i] == '.' && eMail[i + 1] == '.') {              // Проверка на две точки подряд
            correct = false;
            break;
        }
        if (eMail[i] >= 'a' && eMail[i] <= 'z' ||
            eMail[i] >= 'A' && eMail[i] <= 'Z' ||
            eMail[i] >= '0' && eMail[i] <= '9') {     // Два блока для проверки на корректность символов
            correct = true;
        }
        if (eMail[i] == '"' || eMail[i] == '(' || eMail[i] == ')' || eMail[i] == ',' ||
            eMail[i] == ':' || eMail[i] == ';' || eMail[i] == '<' || eMail[i] == '>' ||
            eMail[i] == '[' || eMail[i] == ']' || eMail[i] == '\\') {
            correct = false;
            break;
        }

    }
    if (!foundAtsign) {
        correct = false;
    }
    return correct;
}




bool secondPart(bool& correct, string eMail, int atIndex)
{
    int length = eMail.length();
    if (length < 1 || length > 63) {
        correct = false;
        return correct;
    }

    bool foundAtSign = false; // Переменная для отслеживания наличия символа @

    for (int i = atIndex + 1; i < eMail.length(); i++) {
        if (eMail[i] >= 'a' && eMail[i] <= 'z' || eMail[i] == '-' || eMail[i] >= '0' && eMail[i] <= '9') {
            correct = true;
        }
        else if (eMail[i] == '@') {
            foundAtSign = true;             // Если найден второй символ @  Устанавливаем флаг, что символ @ найден
            correct = false;
            break;
        }
        else {
            correct = false;
            break;
        }
        if (eMail[eMail.length() - 1] == '.') {
            correct = false;
        }
    }
    if (foundAtSign) {
        correct = false; // Если не было символа @, устанавливаем correct в false
    }
    return correct;
}

int main() {

    string eMail;
    bool correct = true;
    string result;
    int atIndex = 0;

    cout << "Please enter e-mail adress: "; cin >> eMail;

    bool isFirstPartCorrect = firstPart(correct, eMail, result, atIndex);
    bool isSecondPartCorrect = secondPart(correct, eMail, atIndex);


    if (isFirstPartCorrect && isSecondPartCorrect) {
        cout << "Yes!";
    }
    else {
        cout << "No";
    }
}