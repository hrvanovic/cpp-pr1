#include <iostream>
using namespace std;
int obrni(int);

int main() {
    int unos, noviBroj;
    do {
        cout << "Unesite broj: ";
        cin >> unos;
    } while(unos < 50 || unos > 5000000);

    cout << "Novi broj:" << obrni(unos);
    return 0;
}

int obrni(int unos) {
    int znamenka, noviBroj = 0;
    while(unos > 0) {
        znamenka = unos % 10;
        if(znamenka % 2 == 0) // Odbaci neparne
            noviBroj = noviBroj * 10 + znamenka;
        unos /= 10;
    }
    return noviBroj;
}
