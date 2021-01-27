#include <iostream>
using namespace std;
float procenat(int);
bool prost(int);

int main() {
    srand((unsigned int) time(NULL));
    
    int n;
    do {
        cout << "Unesite broj n: ";
        cin >> n;
    } while(n < 10 || n > 1000);

    cout << "Procenat: " << procenat(n) << " %" << endl;
    return 0;
}

bool prost(int broj) {
    if(broj <= 1)
        return false;

    for(int i = 2; i <= broj / 2; i++) {
        if(broj % i == 0)
            return false;
    }

    return true;
}

float procenat(int n) {
    int randBr, brojac = 0;
    for(int i = 1; i <= n; i++) {
        randBr = rand() % 1000 + 1;
      //  cout << endl << i << ". " << " " << randBr << ((prost(randBr)) ? " - Prost je" : " - Nije prost") << endl;
        if(prost(randBr))
            brojac++;
    }
    return (brojac * 100) / n;
}
