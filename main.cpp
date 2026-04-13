#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include "TablicaDynamiczna.h"
#include "ListaWiazana.h"

using namespace std;
using namespace std::chrono;

template <typename F>
long long measure_avg(F func) {
    long long total_time = 0;
    const int repeats = 10;

    for (int i = 0; i < repeats; i++) {
        auto s = high_resolution_clock::now();
        func();
        auto e = high_resolution_clock::now();
        total_time += duration_cast<microseconds>(e - s).count();
    }

    return total_time / repeats;
}

int main() {
    vector<int> proby = { 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000 };

    
    cout << "DODAWANIE NA POCZATEK" << endl;
    cout << "N;Tablica;Lista" << endl;
    for (int n : proby) {
        long long t = measure_avg([&]() {
            TablicaDynamiczna tab;
            for (int i = 0; i < n; i++) tab.dodajPoczatek(i);
            });
        long long l = measure_avg([&]() {
            ListaWiazana list;
            for (int i = 0; i < n; i++) list.dodajPoczatek(i);
            });
        cout << n << ";" << t << ";" << l << endl;
    }
    cout << endl;

    
    cout << "DODAWANIE NA KONIEC" << endl;
    cout << "N;Tablica;Lista" << endl;
    for (int n : proby) {
        long long t = measure_avg([&]() {
            TablicaDynamiczna tab;
            for (int i = 0; i < n; i++) tab.dodajKoniec(i);
            });
        long long l = measure_avg([&]() {
            ListaWiazana list;
            for (int i = 0; i < n; i++) list.dodajKoniec(i);
            });
        cout << n << ";" << t << ";" << l << endl;
    }
    cout << endl;


    cout << "WYSZUKIWANIE" << endl;
    cout << "N;Tablica;Lista" << endl;
    for (int n : proby) {
        TablicaDynamiczna tab;
        ListaWiazana list;
        for (int i = 0; i < n; i++) { tab.dodajKoniec(i); list.dodajKoniec(i); }

        long long t = measure_avg([&]() { tab.szukaj(-1); });
        long long l = measure_avg([&]() { list.szukaj(-1); });
        cout << n << ";" << t << ";" << l << endl;
    }
    cout << endl;

    cout << "USUWANIE ZE SRODKA" << endl;
    cout << "N;Tablica;Lista" << endl;
    for (int n : proby) {
        long long t = measure_avg([&]() {
            TablicaDynamiczna tab;
            for (int i = 0; i < n; i++) tab.dodajKoniec(i);
            for (int i = 0; i < 100; i++) tab.usunZIndeksu(tab.szukaj(n / 2 - i));
            });
        long long l = measure_avg([&]() {
            ListaWiazana list;
            for (int i = 0; i < n; i++) list.dodajKoniec(i);
            for (int i = 0; i < 100; i++) list.usunZIndeksu(n / 2 - i);
            });
        cout << n << ";" << t << ";" << l << endl;
    }

    return 0;
}
