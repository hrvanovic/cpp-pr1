#include <iostream>
using namespace std;

struct VremenskaPrognoza {
    char *padavine;
    float *temperatura;
    float *vlaznostVazduha;

    VremenskaPrognoza() {
        padavine = new char[7];
        temperatura = new float;
        vlaznostVazduha = new float;
    }
    
    ~VremenskaPrognoza() {
        padavine = nullptr;
        temperatura = nullptr;
        vlaznostVazduha = nullptr;
    }
    
    void unosPrognoze();
    void ispisPrognoze();
};

void dealokacija(VremenskaPrognoza** niz, int redovi) {
    for(int i = 0; i < redovi; i++) {
        delete redovi[];
    }
    delete[] niz;
    niz = nullptr;
}
void VremenskaPrognoza::unosPrognoze() {
    cin.ignore();
    cout << "Unesite padavine (kisa, snijeg): ";
    cin.getline(padavine, 7);

    cout << "Unesite temperaturu: ";
    cin >> *temperatura;

    cout << "Unesite vlaznost vazduha: ";
    cin >> *vlaznostVazduha;
}

void VremenskaPrognoza::ispisPrognoze() {
    cout << "Padavine: " << padavine << endl;
    cout << "Temperatura: " << *temperatura << endl;
    cout << "Vlaznost vazduha: " << *vlaznostVazduha << endl;
}

void unos(VremenskaPrognoza** niz, int redovi, int kolone) {
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            cout << "***** Meteorog " << i << " dan " << j << " ****";
            (*(niz + i) + j)->unosPrognoze();
        }
    }
}

float* unosStvarnihVelicina(int kolone) {
    float *niz = new float[kolone];
    for(int i = 0; i < kolone; i++) {
        cout << "Unesite stvarnu vrijednost temperature za dan " << i;
        cin >> *(niz + i);
    }
    return niz;
}

void ispis(VremenskaPrognoza** niz, int redovi, int kolone) {
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            cout << "***** Meteorog " << i << " ***** Dan " << j << " ****";
            (*(niz + i) + j)->ispisPrognoze();
        }
    }
}

int provjeraMeteorologa(VremenskaPrognoza** niz, int redovi, int kolone) {
    float *nizStv = unosStvarnihVelicina(kolone);
    int odstupanje = 0, temp, tempStvarna;
    int najmanjeOdstupanje = -1, indexMeteorologa = 0;
    for(int i = 0; i < redovi; i++) {
        for(int j = 0; j < kolone; j++) {
            temp = *(*(niz + i) + j)->temperatura;
            tempStvarna = *(nizStv + j);
            odstupanje += (temp > tempStvarna) ? temp - tempStvarna : tempStvarna - temp;
            if(najmanjeOdstupanje > odstupanje || (i == 0 && j == 0)) {
                najmanjeOdstupanje = odstupanje;
                indexMeteorologa = i;
            }
            odstupanje = 0;
            temp = 0;
            tempStvarna = 0;
        }
    }

    return indexMeteorologa;
}

int main() {
    int redovi, kolone;
    cout << "Unesite broj meteorologa i vremenskih prognoza: ";
    cin >> redovi >> kolone;

    VremenskaPrognoza** niz = new VremenskaPrognoza*[redovi];
    for(int i = 0; i < redovi; i++)
        *(niz + i) = new VremenskaPrognoza[kolone];

    unos(niz, redovi, kolone);
    cout << provjeraMeteorologa(niz, redovi, kolone);
    dealokacija(niz, redovi);
    return 0;
}
