#include <iostream>
using namespace std;
bool func (unsigned a, unsigned b)
{
  unsigned tmp = 0;
  while (tmp < a)
  {
    tmp += b;
    if (!(a ^ tmp))
      return 1;
  }
  return 0;
}
int main (){
    int a , b;
    cin>> a;
    cin>> b;
    cout << func(a , b);
    return 0;
}