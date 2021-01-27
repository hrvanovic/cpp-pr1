#include <iostream>
using namespace std;

int izracunaj(int, int);

int main() {
    int broj, eksponent;
    cout << "Unesite broj i eksponent: ";
    cin >> broj >> eksponent;

    cout << "Rezultat: " <<  izracunaj(broj, eksponent);
    return 0;
}

int izracunaj(int broj, int eksponent) {
    if(eksponent == 0)
        return 1;
    if(eksponent == 1)
        return broj;
    return broj * izracunaj(broj, eksponent - 1);
}
