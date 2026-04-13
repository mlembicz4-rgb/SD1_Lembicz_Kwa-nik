#pragma once

struct Wezel {
    int dane;
    Wezel* nastepny;
    Wezel(int val) : dane(val), nastepny(nullptr) {}
};

class ListaWiazana {
    Wezel* glowa;
    int rozmiar;

public:
    ListaWiazana() : glowa(nullptr), rozmiar(0) {}

    ~ListaWiazana() {
        while (glowa) usunPoczatek();
    }

    void dodajPoczatek(int wartosc) {
        Wezel* nowy = new Wezel(wartosc);
        nowy->nastepny = glowa;
        glowa = nowy;
        rozmiar++;
    }

    void dodajKoniec(int wartosc) {
        if (!glowa) {
            dodajPoczatek(wartosc);
            return;
        }
        Wezel* temp = glowa;
        while (temp->nastepny) temp = temp->nastepny;
        temp->nastepny = new Wezel(wartosc);
        rozmiar++;
    }

    void dodajNaIndeks(int indeks, int wartosc) {
        if (indeks == 0) {
            dodajPoczatek(wartosc);
            return;
        }
        if (indeks < 0 || indeks > rozmiar) return;
        Wezel* temp = glowa;
        for (int i = 0; i < indeks - 1; i++) temp = temp->nastepny;
        Wezel* nowy = new Wezel(wartosc);
        nowy->nastepny = temp->nastepny;
        temp->nastepny = nowy;
        rozmiar++;
    }

    void usunPoczatek() {
        if (!glowa) return;
        Wezel* temp = glowa;
        glowa = glowa->nastepny;
        delete temp;
        rozmiar--;
    }

    void usunKoniec() {
        if (!glowa) return;
        if (!glowa->nastepny) {
            usunPoczatek();
            return;
        }
        Wezel* temp = glowa;
        while (temp->nastepny->nastepny) temp = temp->nastepny;
        delete temp->nastepny;
        temp->nastepny = nullptr;
        rozmiar--;
    }

    void usunZIndeksu(int indeks) {
        if (indeks < 0 || indeks >= rozmiar) return;
        if (indeks == 0) {
            usunPoczatek();
            return;
        }
        Wezel* temp = glowa;
        for (int i = 0; i < indeks - 1; i++) temp = temp->nastepny;
        Wezel* doUsuniecia = temp->nastepny;
        temp->nastepny = doUsuniecia->nastepny;
        delete doUsuniecia;
        rozmiar--;
    }

    int szukaj(int wartosc) {
        Wezel* temp = glowa;
        int indeks = 0;
        while (temp) {
            if (temp->dane == wartosc) return indeks;
            temp = temp->nastepny;
            indeks++;
        }
        return -1;
    }
};