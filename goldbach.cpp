#include <iostream>
using namespace std;
// primjer goldbacha. Ovaj kod je lose optimiziran, imate jos jedan u folderu sa funkcijama.
bool isProst(int);
void autoUnos(int&, int&);

int main() {
     // cout << "Unesite 2 prirodna broja: ";
    //cin >> n1 >> n2;
    int n1, n2;
    autoUnos(n1, n2);
    for(int i = n1; i < n2; i++) {
        for(int j = n1, k = i; j < (i / 2); j++, k--) {
           if(isProst(j) && isProst(k) && ((j + k) % 2 == 0))
                cout << j << " + " << k << " = " << j + k << endl;
        }
    }
    return 0;
}

// Rand number za n1 i n2.
void autoUnos(int &n1, int &n2) {
    n1 = rand() % 20 + 1;
    n2 = rand() % 200 + 1;

    if(n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
}
// Provjerava da li je prost, false da nije.
bool isProst(int broj) {
    for(int i = 2; i < broj; i++) {
        if(broj % i == 0)
            return false;
    }
    return true;
}

