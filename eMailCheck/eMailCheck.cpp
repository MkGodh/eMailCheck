#include <algorithm>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

bool firstPart(bool& correct, string eMail, int& atIndex) {
    int length = eMail.length();


    bool foundAtsign = false;

    if (length < 1 || length > 64) {
        correct = false;
    }

    for (int i = 0; i < eMail.length(); i++) {
        if (eMail[0] ==
            '.') {
            correct = false;
            break;
        }

        if (eMail[i] ==
            '@') {
            foundAtsign = true;
            correct = true;
            atIndex = i;
            break;
        }

        if (eMail[i] == '.' &&
            eMail[i + 1] == '.') {
            correct = false;
            break;
        }
        if (eMail[i] >= 'a' && eMail[i] <= 'z' ||
            eMail[i] >= 'A' && eMail[i] <= 'Z' ||
            eMail[i] >= '0' &&
            eMail[i] <=
            '9') {
            correct = true;
        }
        if (eMail[i] == '"' || eMail[i] == '(' || eMail[i] == ')' ||
            eMail[i] == ',' || eMail[i] == ':' || eMail[i] == ';' ||
            eMail[i] == '<' || eMail[i] == '>' || eMail[i] == '[' ||
            eMail[i] == ']' || eMail[i] == '\\') {
            correct = false;
            break;
        }
    }
    if (!foundAtsign) {
        correct = false;
    }
    return correct;
}

bool secondPart(bool& correct, string eMail, int atIndex) {
    int count = 0;
    int length = eMail.length();
    if (length < 1 || length > 63) {
        correct = false;
        return correct;
    }

    bool foundAtSign = false;

    for (int i = atIndex + 1; i < eMail.length(); i++) {
        if (eMail[i] >= 'a' && eMail[i] <= 'z' || eMail[i] == '-' ||
            eMail[i] >= '0' && eMail[i] <= '9') {
            correct = true;
        }
        else if (eMail[i] == '.') {
            count++;
            if (count > 2) {
                correct = false;
                break;
            }
        }
        else if (eMail[i] == '@') {
            foundAtSign = true;

            correct = false;
            break;
        }
        else {
            correct = false;
            break;
        }
    }
    if (foundAtSign) {
        correct = false;
    }
    if (eMail[eMail.length() - 1] == '.') {
        correct = false;
    }
    return correct;
}

int main() {

    string eMail;
    bool correct = true;
    int atIndex = 0;

    cout << "Please enter e-mail adress: ";
    cin >> eMail;

    bool isFirstPartCorrect = firstPart(correct, eMail, atIndex);
    bool isSecondPartCorrect = secondPart(correct, eMail, atIndex);

    if (isFirstPartCorrect && isSecondPartCorrect) {
        cout << "Yes!";
    }
    else {
        cout << "No";
    }
}