#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include <iostream>
using namespace std;


struct Wezel {            // Struktura reprezentuj�ca pojedynczy element listy dwukierunkowej
    int data;          // Warto�� przechowywana w w�le
    Wezel* prev;       // Wska�nik na poprzedni w�ze�
    Wezel* next;       // Wska�nik na nast�pny w�ze�
    Wezel(int value);     // Konstruktor inicjuj�cy warto�� w�z�a
};


class ListaDwukierunkowa {     // Klasa reprezentuj�ca list� dwukierunkow�
private:
    Wezel* head;       // Wska�nik na pierwszy element listy
    Wezel* tail;       // Wska�nik na ostatni element listy

public:
    ListaDwukierunkowa();        // Konstruktor inicjuj�cy pust� list�
    ~ListaDwukierunkowa();       // Destruktor usuwaj�cy wszystkie elementy listy

    void addFront(int value);    // Dodaje element na pocz�tek listy
    void addBack(int value);     // Dodaje element na koniec listy
    void addAt(int index, int value);    // Dodaje element pod wskazany indeks

    void removeFront();          // Usuwa element z pocz�tku listy
    void removeBack();           // Usuwa element z ko�ca listy
    void removeAt(int index);    // Usuwa element pod wskazanym indeksem

    void display() const;        // Wy�wietla elementy listy od pocz�tku do ko�ca
    void displayReverse() const;    // Wy�wietla elementy listy od ko�ca do pocz�tku

    void displayNext(Wezel* wezel) const;    // Wy�wietla warto�� nast�pnego elementu
    void displayPrev(Wezel* wezel) const;    // Wy�wietla warto�� poprzedniego elementu
    void clear();               // Czy�ci ca�� list�, usuwaj�c wszystkie elementy
};

#endif
