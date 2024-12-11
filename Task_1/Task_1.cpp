#include <iostream>
#include <string>


using namespace std;


string DopolnCod(const string& binaryNumber) {// O(n)+O(n)= O(n)
    
    
    if (binaryNumber[0] != '1') {
        return binaryNumber;
    }

    string inverted = binaryNumber;
    for (int i = 1; i < inverted.size(); ++i) {// O(n + n +2n + 1) = O( n )
        inverted[i] = (inverted[i] == '0') ? '1' : '0';
    }

    
    int plus = 1;
    for (int i = inverted.size() - 1; i >= 1; --i) { //O ( 1 + n + n + 3(4)n ) = O ( n )
        if (inverted[i] == '1' && plus == 1) {
            inverted[i] = '0';
        } else {
            inverted[i] += plus;
            plus = 0;
        }
    }

    return inverted;
}

int main() {//O(n)+O(n)=O(n)
    string binaryNumber;

    cout << "Введите число в прямом коде (первый символ знаковый бит) : ";
    cin >> binaryNumber;

   for (int i =0 ; i < binaryNumber.size(); ++i ){ // O (1 + n + n + 5n) =O (n)
    if (binaryNumber.empty() || (binaryNumber[i] != '0' && binaryNumber[i] != '1')) {
        cout << "Некорректный ввод!" << endl;
        return 0;
    }
   }


    cout << "Число в дополнительном коде: " << DopolnCod(binaryNumber)<< endl;//O(n)

    return 0;
}
