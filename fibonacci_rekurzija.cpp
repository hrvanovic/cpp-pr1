#include <iostream>
using namespace std;
// fibonacci sa rekurzijom.
void ispuni(int*, int);
void ispis(int*, int);
int fibonacci(int, int);
int main() {
    int velicinaNiza;
    cout << "Unesite velicinu niza: ";
    cin >> velicinaNiza;

    int* niz = new int[velicinaNiza];
    ispuni(niz, velicinaNiza);
    ispis(niz, velicinaNiza);
    return 0;
}

void ispis(int* niz, int max) {
    for(int i = 0; i < max; i++)
        cout << *(niz + i) << endl;
}
void ispuni(int* niz, int vel) {
    for(int i = 0; i < vel; i++)
        *(niz + i) = fibonacci(i, vel);
}

int fibonacci(int index, int max) {
    if(index <= 1)
        return 1;
    return fibonacci(index - 1, max) + fibonacci(index - 2, max);
}
