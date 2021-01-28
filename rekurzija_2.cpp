#include <iostream>
using namespace std;
// Umnozak prethodna 2 broja u nizu.

void ispuni(int*, int, int);
void ispis(int*, int);

int main() {
    int n;

    do {
        cout << "Unesite broj n: ";
        cin >> n;
    } while(n < 2);

    int *niz = new int;
    ispuni(niz, 0, n);
    ispis(niz, n);
    return 0;
}

void ispis(int* niz, int max) {
    for(int i = 0; i < max; i++)
        cout << *(niz + i) << endl;
}

void ispuni(int* niz, int index, int max) {
    if(index > max)
        return;
    
    if(index == 0)
        *niz = 1;
    else if(index == 1)
        *(niz + 1) = 3;
    else
        *(niz + index) = *(niz + index - 1) * *(niz + index - 2);
    ispuni(niz, index + 1, max);
}
