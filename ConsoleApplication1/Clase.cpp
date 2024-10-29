#include <iostream>
#include <cstring>

using namespace std;

// Clasa pentru Floare
class Floare {
public:
    // Atribute
    const char* nume;            // Atribut normal
    int petale;                  // Atribut normal
    static int numarFlori;       // Atribut static
    static const int cod = 2024; // Atribut constant
    float* pret;                 // Pointer pentru alocare in HEAP

    // Constructori
    Floare() : nume("Unknown"), petale(0) {
        pret = new float(0.0); // Alocare în HEAP
    }

    Floare(const char* n, int p) : petale(p) {
        nume = new char[strlen(n) + 1];
        strcpy((char*)nume, n);
        pret = new float(0.0); // Alocare în HEAP
        numarFlori++;
    }

    Floare(const char* n, int p, float price) : petale(p) {
        nume = new char[strlen(n) + 1];
        strcpy((char*)nume, n);
        pret = new float(price); // Alocare în HEAP
        numarFlori++;
    }

    // Funcție statică
    static void afiseazaNumarFlori() {
        cout << "Numarul total de flori: " << numarFlori << endl;
    }

    // Destructor
    ~Floare() {
        delete[] pret; // Eliberare memorie
        delete[](char*)nume; // Eliberare memorie
        numarFlori--;
    }
};

// Inițializare atribut static
int Floare::numarFlori = 0;

// Clasa pentru Trandafir
class Trandafir : public Floare {
public:
    // Atribute specifice
    const char* culoare; // Atribut normal
    static int numarTrandafiri; // Atribut static

    // Constructori
    Trandafir() : Floare(), culoare("Unknown") {
        numarTrandafiri++;
    }

    Trandafir(const char* n, int p, const char* c) : Floare(n, p), culoare(c) {
        numarTrandafiri++;
    }

    Trandafir(const char* n, int p, const char* c, float price) : Floare(n, p, price), culoare(c) {
        numarTrandafiri++;
    }

    // Funcție statică
    static void afiseazaNumarTrandafiri() {
        cout << "Numarul total de trandafiri: " << numarTrandafiri << endl;
    }

    // Destructor
    ~Trandafir() {
        numarTrandafiri--;
    }
};

// Inițializare atribut static
int Trandafir::numarTrandafiri = 0;

// Clasa pentru Lalea
class Lalea : public Floare {
public:
    // Atribute specifice
    const char* sezon; // Atribut normal
    static int numarLalele; // Atribut static

    // Constructori
    Lalea() : Floare(), sezon("Unknown") {
        numarLalele++;
    }

    Lalea(const char* n, int p, const char* s) : Floare(n, p), sezon(s) {
        numarLalele++;
    }

    Lalea(const char* n, int p, const char* s, float price) : Floare(n, p, price), sezon(s) {
        numarLalele++;
    }

    // Funcție statică
    static void afiseazaNumarLalele() {
        cout << "Numarul total de lalele: " << numarLalele << endl;
    }

    // Destructor
    ~Lalea() {
        numarLalele--;
    }
};

// Inițializare atribut static
int Lalea::numarLalele = 0;

int main() {
    // Creare și inițializare obiecte
    Floare floare1;
    Floare floare2("Violeta", 5);
    Floare floare3("Liliac", 6, 10.5);

    Trandafir trandafir1;
    Trandafir trandafir2("Trandafir Rosu", 7, "Rosu");
    Trandafir trandafir3("Trandafir Alb", 8, "Alb", 12.5);

    Lalea lalea1;
    Lalea lalea2("Lalea Galbena", 4, "Primavara");
    Lalea lalea3("Lalea Rosie", 3, "Primavara", 8.0);

    // Afișare număr total flori
    Floare::afiseazaNumarFlori();
    Trandafir::afiseazaNumarTrandafiri();
    Lalea::afiseazaNumarLalele();

    return 0;
}