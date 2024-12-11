#include <iostream>
#include <string>

using namespace std;

string Urawn(string& binaryNumber, int k) {// O ( K + 2 + 1)=O(n)
    if (k == 0) {
       return binaryNumber;  
    }
    binaryNumber.insert(1, k, '0');  // O(k) 
    return binaryNumber;  
}

string DopolnCod(const string& binaryNumber) {// O( n ) + O(n) = O(n)
    if (binaryNumber[0] != '1') {
        return binaryNumber;  
    }

    string inverted = binaryNumber;
    for (int i = 1; i < inverted.size(); ++i) {  // O(1 + n + n + 2n)=O(n)
        inverted[i] = (inverted[i] == '0') ? '1' : '0';  
    }

    int plus = 1;
    for (int i = inverted.size() - 1; i >= 1; --i) {  // O(1 + n + n + 4n) = O(n)
        if (inverted[i] == '1' && plus == 1) {
            inverted[i] = '0';
        } else {
            inverted[i] += plus;
            plus = 0;
        }
    }

    return inverted;  
}

string BinSum(const string& Num1, const string& Num2) {//O(n)
    string Sum(Num1);
    int plus = 0;

    for (int i = Num1.size() - 1; i >= 0; --i) {  // O(1 + n + n + 11n) = O(n)
        if (Num1[i] == '0' && Num2[i] == '0' && plus == 0) {
            Sum[i] = '0';
        }
        else if ((Num1[i] == '1' && Num2[i] == '1' && plus == 0) || 
                 (Num1[i] == '1' && Num2[i] == '0' && plus == 1) || 
                 (Num1[i] == '0' && Num2[i] == '1' && plus == 1)) {
            Sum[i] = '0';
            plus = 1;
        }
        else if ((Num1[i] == '1' && Num2[i] == '0' && plus == 0) || 
                 (Num1[i] == '0' && Num2[i] == '0' && plus == 1) || 
                 (Num1[i] == '0' && Num2[i] == '1' && plus == 0)) {
            Sum[i] = '1';
            plus = 0;
        }
        else {
            Sum[i] = '1';
            plus = 1;
        }
    }
    return Sum;  
}

string PremCod(string binaryNumber) {//O(n)+ O(n) = O(n)
    if (binaryNumber[0] == '0') {
        return binaryNumber;  
    }

    for (int i = binaryNumber.size() - 1; i > 0; --i) {  // O(1 + n + n +3n) = O(n)
        if (binaryNumber[i] == '0') {
            binaryNumber[i] = '1';
        }
        if (binaryNumber[i] == '1') {
            binaryNumber[i] = '0';
            break;
        }
    }

    string inverted = binaryNumber;
    for (int i = 1; i < inverted.size(); ++i) {  // O( 1 + n + n + 2n)= O(n)
        inverted[i] = (inverted[i] == '0') ? '1' : '0';  
    }
    return inverted;  
}

int main() {// O(n)+O(n)+ O(n)+O(n) =O(n)
    string Num1;
    string Num2;

    cout << "Введите первое число в прямом коде (первый символ знаковый бит) : ";
    cin >> Num1;  

    for (int i = 0; i < Num1.size(); ++i) {  // O(1 + n + n + 5n)=O(n)
        if (Num1.empty() || (Num1[i] != '0' && Num1[i] != '1')) {  //
            cout << "Некорректный ввод!" << endl;  
            return 0;  
        }
    }

    cout << "Введите второе число в прямом коде (первый символ знаковый бит) : ";
    cin >> Num2;  

    for (int i = 0; i < Num2.size(); ++i) {  // O(1 + n + n + 5n)=O(n)
        if (Num2.empty() || (Num2[i] != '0' && Num2[i] != '1')) {  
            cout << "Некорректный ввод!" << endl;  //
            return 0;  
        }
    }

    int k1 = 0, k2 = 0;
    if (Num1.size() < Num2.size()) {
        k1 = Num2.size() - Num1.size();  
    }
    else if (Num1.size() > Num2.size()) {
        k2 = Num1.size() - Num2.size();  
    }

    string a = DopolnCod(Urawn(Num1, k1)), b = DopolnCod(Urawn(Num2, k2));  // O(n)+O(n)+ O(n)+O(n) =O(n)
    string c = BinSum(a, b);  // O(n)

    cout << "Числа в дополнительном коде :" << endl << a << endl << b << endl;
    cout << "Сумма в дополнительном коде:" << endl << c << endl;
    cout << "Сумма в прямом коде :" << endl << PremCod(c) << endl;

    return 0;  
}
