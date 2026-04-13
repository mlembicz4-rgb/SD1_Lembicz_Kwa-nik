#pragma once
#include <iostream>
#include <stdexcept>

class TablicaDynamiczna {
    int* dane;
    int pojemnosc;
    int rozmiar;

    void zmienRozmiar() {
        pojemnosc *= 2;
        int* noweDane = new int[pojemnosc];
        for (int i = 0; i < rozmiar; i++) {
            noweDane[i] = dane[i];
        }
        delete[] dane;
        dane = noweDane;
    }

public:
    TablicaDynamiczna(int n = 2) : pojemnosc(n), rozmiar(0) {
        dane = new int[pojemnosc];
    }

    ~TablicaDynamiczna() {
        delete[] dane;
    }

    void dodajPoczatek(int wartosc) {
        dodajNaIndeks(0, wartosc);
    }

    void dodajKoniec(int wartosc) {
        if (rozmiar == pojemnosc) zmienRozmiar();
        dane[rozmiar++] = wartosc;
    }

    void dodajNaIndeks(int indeks, int wartosc) {
        if (indeks < 0 || indeks > rozmiar) throw std::out_of_range("Blad");
        if (rozmiar == pojemnosc) zmienRozmiar();
        for (int i = rozmiar; i > indeks; i--) {
            dane[i] = dane[i - 1];
        }
        dane[indeks] = wartosc;
        rozmiar++;
    }

    void usunPoczatek() {
        if (rozmiar > 0) usunZIndeksu(0);
    }

    void usunKoniec() {
        if (rozmiar > 0) rozmiar--;
    }

    void usunZIndeksu(int indeks) {
        if (indeks < 0 || indeks >= rozmiar) throw std::out_of_range("Blad");
        for (int i = indeks; i < rozmiar - 1; i++) {
            dane[i] = dane[i + 1];
        }
        rozmiar--;
    }

    int szukaj(int wartosc) {
        for (int i = 0; i < rozmiar; i++) {
            if (dane[i] == wartosc) return i;
        }
        return -1;
    }
};