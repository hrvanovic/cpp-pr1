#include <iostream>
using namespace std;
struct Uposlenik {
    char *iD;
    char *imePrezime;
    float *plata;

    Uposlenik() {
        iD = new char[20];
        imePrezime = new char[30];
        plata = new float;
    }

    void unos();
    void ispisRadnika();
};

void Uposlenik::unos() {
    cin.ignore();
    cout << "Unesite ID radnika: ";
    cin.getline(iD, 20);

    cout << "Unesite Ime i Prezime radnika: ";
    cin.getline(imePrezime, 30);

    cout << "Unesite platu radnika: ";
    cin >> *plata;
}

void Uposlenik::ispisRadnika() {
    cout << "ID: " << iD << endl;
    cout << "Ime i Prezime: " << imePrezime << endl;
    cout << "Plata: " << *plata << endl;
    cout << endl;
}

void ispis(Uposlenik** niz, int redovi, int kolone) {
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            cout << "**** Odjel " << i << " Radnik " << j << " ****" << endl;
            (*(niz + i) + j)->ispisRadnika();
            cout << endl;
        }
    }
}
int najveciProsjekOdjela(Uposlenik** niz, int redovi, int kolone, int& odjel) {
    int suma = 0, tempProsjek, najveciProsjek = 0;
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            suma += *(*(niz + i) + j)->plata;
            tempProsjek = suma / kolone;
        }
        if(tempProsjek > najveciProsjek) {
            najveciProsjek = tempProsjek;
            odjel = i;
        }
        tempProsjek = 0;
        suma = 0;
    }

    return najveciProsjek;
}

int main() {
    int redovi, kolone;
    int indeksOdjelaProsjek;
    cout << "Unesite redove i kolone: ";
    cin >> redovi >> kolone;

    Uposlenik **niz = new Uposlenik*[redovi];

    for(int i = 0; i < redovi; i++)
        *(niz + i) = new Uposlenik[kolone];

    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            (*(niz + i) + j)->unos();
        }
    }
    ispis(niz, redovi, kolone);
    cout << "Najveci prosjek plate je " << najveciProsjekOdjela(niz, redovi, kolone, indeksOdjelaProsjek) << " u odjelu " << indeksOdjelaProsjek;
    return 0;
}
