#include <iostream>
#include <vector>

using namespace std;

int countOnes(int n) {// O(log(n)) 
    int count = 0;
    while (n) { // O(log(n))
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

void ZapolnGroops(vector<int>& groops){ // O(29 * log(i)) ~= O(log(i))
    groops.push_back(0); 
    groops.push_back(32); 

    
    for (int i = 1; i <= 29; ++i) { // O(29 * log(i))
        int onesCount = countOnes(i);// O(log(i)) 
        int increment = 0;

        if (onesCount == 1) {
            increment = 16;  
        } else if (onesCount == 2) {
            increment = 8;   
        } else if (onesCount == 3) {
            increment = 4;  
        } else if (onesCount == 4) {
            increment = 2;   
        }

        groops.push_back(groops.back() + increment);
    }
      
}

vector<int> getOneBit(int n) { // O(log(n))
    vector<int> indices;
    int index = 0; 
    while (n > 0) { // O(log(n))
       
        if (n & 1) {
            indices.push_back(index);
        }
        n >>= 1;
        index++;
    }

    return indices;
}

void FindGroop(const vector<int>& groops, vector<bool>& slaves, const vector<bool> barrels) { // O( groops.size() *( log(i) +O(Ones.size()) * (groops[i+1] - groops[i])) ~= O(30 * (log(30) + log(30) * 16) = O(1)
    for (int i = 0; i < groops.size(); ++i) { // O(groops.size()), где groops.size() = 30
        vector<int> Ones = getOneBit(i); // O(log(i)), но максимум O(log(30))
        for (int j = 0; j < Ones.size(); ++j) { // O(Ones.size()), максимум O(log(30))
            for (int k = groops[i]; k < groops[i + 1]; ++k) { // O(groops[i+1] - groops[i]), максимум O(16)
                if (!slaves[Ones[j]]) { 
                    slaves[Ones[j]] = barrels[k] && 1; 
                }
            }
        }
    }
} 

int NumberGroop_Barr(const vector<bool>& slaves){ // O(slaves.size())
    int result =0 ;
    int razr =1;
    for (int i =0 ; i < slaves.size(); ++i){ // O(slaves.size())
      result += slaves[i]* razr;
      razr *= 2;
     }
     return result;
}

void CleanSlaves(vector<bool>& slaves){ // O(slaves.size())
    for (int i = 0 ; i < slaves.size(); ){ // O(slaves.size())
        if (slaves[i]){
         slaves.erase(slaves.begin() + i);
        }
        else ++i;
    }
}

void findBarrel(int number,const vector <int>& groops, vector<bool>& slaves , const vector<bool> barrels ){ // O(16 *( log(16) + log(16))) ~= O(1)
     for(int k =groops[number]  , i = 0 ; k < groops[number+1]  ; ++k , ++i){ // O(groops[number+1] - groops[number]), максимум O(16)
          vector<int>Ones = getOneBit(i); // O(log(i)), максимум O(log(16))
          for(int j = 0; j < Ones.size(); ++j){  // O(Ones.size()), максимум O(log(16))
            if(! slaves[Ones[j]]){
             slaves[Ones[j]]=barrels[k] && 1;
            }
          }
         }
}

int main() { // ~=O(1) 
  
    vector<bool> barrels(240, false);  
    vector<bool> slaves(5, false);
     vector<int> groops;
     ZapolnGroops(groops); // ~=O(1) 
    /* for (int value : groops) {
        cout << value << " ";
    }
    cout << endl;*/

    cout << "Отравите бочку .Введите номер отравленой бочки .\n";

    int poisen_bar;
    cin >> poisen_bar;

    barrels[poisen_bar - 1] = true;  
    
    FindGroop(groops , slaves ,barrels); // ~=O(1)
     /*for (int i =slaves.size()-1 ; i >=0; --i){
      cout << slaves[i];
    }
    cout << endl;*/
    int a=NumberGroop_Barr(slaves); // ~=O(1)
    //cout <<"Номер группы : "<< a << endl;
    CleanSlaves(slaves); // O(1)
    findBarrel(a , groops , slaves , barrels); // ~=O(1)
    
    /*for (int i =slaves.size()-1 ; i >=0; --i){
      cout << slaves[i];
    }
    cout << endl;*/
    
    
    int b=NumberGroop_Barr(slaves) + groops[a] + 1; // ~=O(1)
    cout << "Отравленная бочка : " << b;
    return 0;
}
