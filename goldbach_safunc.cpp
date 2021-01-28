#include <iostream>
using namespace std;
// goldbach
void autoUnos(int&, int&);
void ispis(int, int);
bool paran(int);
bool prost(int);
void goldbach(int);
int main() {
    int n1, n2;
    autoUnos(n1, n2);
    cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
    ispis(n1, n2);
    return 0;
}

void autoUnos(int& n1, int& n2) {
    n1 = rand() % 49 + 1;
    n2 = rand() % 100 + 1;

    if(n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
}

void ispis(int n1, int n2) {
    (paran(n1)) ? n1 : n1 = n1 + 1;
    for(int i = n1; i <= n2; i = i + 2) {
        goldbach(i);
    }
}

bool paran(int broj) {
    if(broj % 2 == 0)
        return true;

    return false;
}
bool prost(int broj) {
    if(broj <= 1)
        return false;
    for(int i = 2; i <= (broj / 2); i++) {
        if(broj % i == 0)
            return false;
    }

    return true;
}

void goldbach(int broj) {
    for(int i = 0, j = broj; i <= (broj / 2); i++, j--) {
        if(prost(i) && prost(j))
            cout << i << " + " << j << " = " << i + j << endl;
    }
}
