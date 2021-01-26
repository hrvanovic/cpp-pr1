#include <iostream>
using namespace std;

int obrni(int);
bool prost(int);

int main() {
    int unos;
    cout << "Unesite broj:";
    cin >> unos;

    if(unos == obrni(unos))
        cout << "Broj je polindrom" << "\t" << obrni(unos) << endl;
    else
        cout << "Broj nije polindrom" << endl;

    if(prost(unos))
        cout << "Broj je prost";
    else
        cout << "Broj nije prost";
    return 0;
}

// 123 to 321
int obrni(int broj) {
    int obrnut = 0, znamenka;
    while(broj > 0) {
        znamenka = broj % 10;
        obrnut = (obrnut * 10) + znamenka;
        broj /= 10;
    }
    return obrnut;
}

bool prost(int broj) {
    if(broj <= 1)
        return false;

    for(int i = 2; i < broj / 2; i++) {
        if(broj % i == 0)
            return false;
    }

    return true;
}
