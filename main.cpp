#include <iostream>
#include <chrono>
#include <string>
#include "TablicaDynamiczna.h"
#include "ListaWiazana.h"

using namespace std;
using namespace std::chrono;

void log(string op, long long t, long long l) {
    cout << op << ":" << endl;
    cout << "  Tablica: " << t << " us | Lista: " << l << " us" << endl;
}

int main() {
    const int N = 3000;
    TablicaDynamiczna tab;
    ListaWiazana list;

    auto s = high_resolution_clock::now();
    for (int i = 0; i < N; i++) tab.dodajPoczatek(i);
    auto e = high_resolution_clock::now();
    long long t1 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < N; i++) list.dodajPoczatek(i);
    e = high_resolution_clock::now();
    long long l1 = duration_cast<microseconds>(e - s).count();
    log("1. Dodawanie na poczatek", t1, l1);

    s = high_resolution_clock::now();
    for (int i = 0; i < N; i++) tab.dodajKoniec(i);
    e = high_resolution_clock::now();
    long long t2 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < N; i++) list.dodajKoniec(i);
    e = high_resolution_clock::now();
    long long l2 = duration_cast<microseconds>(e - s).count();
    log("2. Dodawanie na koniec", t2, l2);

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) tab.dodajNaIndeks(N / 2, i);
    e = high_resolution_clock::now();
    long long t3 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) list.dodajNaIndeks(N / 2, i);
    e = high_resolution_clock::now();
    long long l3 = duration_cast<microseconds>(e - s).count();
    log("3. Dodawanie na wybrany indeks", t3, l3);

    s = high_resolution_clock::now();
    tab.szukaj(-1);
    e = high_resolution_clock::now();
    long long t4 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    list.szukaj(-1);
    e = high_resolution_clock::now();
    long long l4 = duration_cast<microseconds>(e - s).count();
    log("4. Wyszukiwanie elementu", t4, l4);

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) tab.usunZIndeksu(N / 2);
    e = high_resolution_clock::now();
    long long t5 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) list.usunZIndeksu(N / 2);
    e = high_resolution_clock::now();
    long long l5 = duration_cast<microseconds>(e - s).count();
    log("5. Usuwanie z wybranego indeksu", t5, l5);

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) tab.usunPoczatek();
    e = high_resolution_clock::now();
    long long t6 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) list.usunPoczatek();
    e = high_resolution_clock::now();
    long long l6 = duration_cast<microseconds>(e - s).count();
    log("6. Usuwanie z poczatku", t6, l6);

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) tab.usunKoniec();
    e = high_resolution_clock::now();
    long long t7 = duration_cast<microseconds>(e - s).count();

    s = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) list.usunKoniec();
    e = high_resolution_clock::now();
    long long l7 = duration_cast<microseconds>(e - s).count();
    log("7. Usuwanie z konca", t7, l7);

    return 0;
}