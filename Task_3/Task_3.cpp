#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Alphabet(int base) {  // O(base)
    string alphabet;

    for (int i = 0; i < 10 && alphabet.size() < base; ++i)  // O(n)
        alphabet += ('0' + i);

    for (int i = 0; i < 26 && alphabet.size() < base; ++i)  // O(n)
        alphabet += ('A' + i);

    for (int i = 0; i < 26 && alphabet.size() < base; ++i)  // O(n)
        alphabet += ('a' + i);

    return alphabet;  
}

int charToValue(char c, const string& alphabet) {  // O(n)
    return alphabet.find(c);  // O(n)
}

char valueToChar(int value, const string& alphabet) {  
    return alphabet[value]; 
}

string Zeros(const string& num, int newLength) {  // O(newLength - num.length())
    string result = num;

    for (int i = 0; i < newLength - num.length(); ++i) {  // O(newLength - num.length())
        result = '0' + result;  
    }

    return result;  
}

string add(string& num1, string& num2, const string& alphabet) {  // O(n)
    if (num1[0] == '-') {  
        num1.erase(0, 1);  // O(n)
    }
    if (num2[0] == '-') {  
        num2.erase(0, 1);  // O(n)
    }
    int maxLength = max(num1.length(), num2.length());  
    num1 = Zeros(num1, maxLength);  // O(n)
    num2 = Zeros(num2, maxLength);  // O(n)
    int base = alphabet.size();  
    string result;  
    int carry = 0;  
    for (int i = num1.size() - 1; i >= 0; --i) {  // O(n)
        int promegh = charToValue(num1[i], alphabet) + charToValue(num2[i], alphabet) + carry; 

        if (promegh < base) {  
            result += valueToChar(promegh, alphabet);  
            carry = 0; 
        }
        else {  
            result += valueToChar(promegh - base, alphabet); 
            carry = 1;  
        }
    }
    if (carry == 1) {  
        result += '1';  
    }
    reverse(result.begin(), result.end());  // O(n)
    return result;  
}

bool bigger(const string& num1, const string& num2, const string& alphabet, int i) {  // O(n)
    if (i == num1.size()) {  
        return true;  
    }

    if (charToValue(num1[i], alphabet) > charToValue(num2[i], alphabet)) {  
        return true;  
    }
    else if (charToValue(num1[i], alphabet) < charToValue(num2[i], alphabet)) {  
        return false;  
    }
    else  
        return bigger(num1, num2, alphabet, i + 1);  // O(n)
}

string minusic(string& num1, string& num2, const string& alphabet) {  // O(n)
    if (num1[0] == '-') {  
        num1.erase(0, 1);  // O(n)
    }
    if (num2[0] == '-') {  
        num2.erase(0, 1);  // O(n)
    }
    int maxLength = max(num1.length(), num2.length());  
    num1 = Zeros(num1, maxLength);  // O(n)
    num2 = Zeros(num2, maxLength);  // O(n)
    int base = alphabet.size();  
    string result, first, second;  
    int carry = 0;  
    if (bigger(num1, num2, alphabet, 0)) {  
        first = num1;  
        second = num2;  
        result += '+';  
    }
    else {  
        first = num2;  
        second = num1;  
        result += '-';  
    }

    for (int i = first.size() - 1; i >= 0; --i) {  // O(n)
        int promegh = charToValue(first[i], alphabet) - charToValue(second[i], alphabet) - carry;  

        if (promegh < 0) {  
            result += valueToChar(promegh + base, alphabet);  
            carry = 1; 
        }
        else {  
            result += valueToChar(promegh, alphabet);  
            carry = 0;  
        }
    }

    reverse(result.begin() + 1, result.end());  // O(n)
    return result; 
}

int main() {  //O(n)
    int base;  
    cout << "Введите основание системы счисления : ";  
    cin >> base; 

    /*if (base < 2 || base > 62) {
    cout << "Неверное основание системы счисления." << endl;
    return 1;
}*/ 

    string alphabet = Alphabet(base);  // O(n)

    string num1, num2; 
    char operation;  

    cout << "Введите первое число: "; 
    cin >> num1;  

    cout << "Введите операцию (+ или -): ";  
    cin >> operation;  

    cout << "Введите второе число: "; 
    cin >> num2; 

    string result; 
    if ((operation == '+' && num1[0] != '-' && num2[0] != '-') || (operation == '-' && num1[0] != '-' && num2[0] == '-')) {  
        result = add(num1, num2, alphabet);  // O(n)
    }
    else if ((operation == '-' && num1[0] != '-' && num2[0] != '-') || (operation == '+' && num1[0] != '-' && num2[0] == '-')) {  
        result = minusic(num1, num2, alphabet);  // O(n)
    }
    else if ((operation == '+' && num1[0] == '-' && num2[0] == '-') || (operation == '-' && num1[0] == '-' && num2[0] != '-')) {  
        result = '-' + add(num1, num2, alphabet);  // O(n)
    }
    else if ((operation == '-' && num1[0] == '-' && num2[0] == '-') || (operation == '+' && num1[0] == '-' && num2[0] != '-')) {  
        result = minusic(num2, num1, alphabet);  // O(n)
    }
    else {  
        cout << "Поддерживаются только операции + и -." << endl;  
        return 1;  
    }

    cout << "Результат: " << result << endl;  
    return 0;  
}
