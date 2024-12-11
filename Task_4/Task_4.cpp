#include <iostream>

using namespace std;

bool isDividedBy5(unsigned number) {//O(n)
  int s = 3;
  int q = number >> 1;
  int r = number & 1;
  int R = (r << 1) + r;
  int a = q + R;
  if (a == 5 || a == 10){
    return 1;
  }
  else if (a < 5){
    return 0;
  }
  else 
    return isDividedBy5(a);  // O(n)
}

bool isDividedBy73(unsigned number) {//O(n)
  int s = 37;
  int q = number >> 1;
  int r = number & 1;
  int R = (r << 5) + (r << 2) + r;
  int a = q + R;
  if (a == 73 ){
    return 1;
  }
  else if (a < 73){
    return 0;
  }
  else 
    return isDividedBy73(a);  // O(n)
}

bool isDividedBy151(unsigned number) {//O(n)
  int s = 76;
  int q = number >> 1;
  int r = number & 1;
  int R = (r << 6) + (r << 3) + (r << 2);
  int a = q + R;
  if (a == 151 ){
    return 1;
  }
  else if (a < 151){
    return 0;
  }
  else 
    return isDividedBy151(a);  // O(n)
}

int main() {//O(n)
    unsigned number;

    cout << "Введите число: ";
    cin >> number;

    cout << "Проверка делимости:\n";
    cout << "На 5: " << (isDividedBy5(number) ? "Да" : "Нет") << endl;  // O(n)
    cout << "На 73: " << (isDividedBy73(number) ? "Да" : "Нет") << endl;  // O(n)
    cout << "На 151: " << (isDividedBy151(number) ? "Да" : "Нет") << endl;  // O(n)

    return 0;
}
