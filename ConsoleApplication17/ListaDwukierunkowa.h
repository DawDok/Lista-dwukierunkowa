#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include <iostream>
using namespace std;


struct Wezel {            // Struktura reprezentuj¹ca pojedynczy element listy dwukierunkowej
    int data;          // Wartoœæ przechowywana w wêŸle
    Wezel* prev;       // WskaŸnik na poprzedni wêze³
    Wezel* next;       // WskaŸnik na nastêpny wêze³
    Wezel(int value);     // Konstruktor inicjuj¹cy wartoœæ wêz³a
};


class ListaDwukierunkowa {     // Klasa reprezentuj¹ca listê dwukierunkow¹
private:
    Wezel* head;       // WskaŸnik na pierwszy element listy
    Wezel* tail;       // WskaŸnik na ostatni element listy

public:
    ListaDwukierunkowa();        // Konstruktor inicjuj¹cy pust¹ listê
    ~ListaDwukierunkowa();       // Destruktor usuwaj¹cy wszystkie elementy listy

    void addFront(int value);    // Dodaje element na pocz¹tek listy
    void addBack(int value);     // Dodaje element na koniec listy
    void addAt(int index, int value);    // Dodaje element pod wskazany indeks

    void removeFront();          // Usuwa element z pocz¹tku listy
    void removeBack();           // Usuwa element z koñca listy
    void removeAt(int index);    // Usuwa element pod wskazanym indeksem

    void display() const;        // Wyœwietla elementy listy od pocz¹tku do koñca
    void displayReverse() const;    // Wyœwietla elementy listy od koñca do pocz¹tku

    void displayNext(Wezel* wezel) const;    // Wyœwietla wartoœæ nastêpnego elementu
    void displayPrev(Wezel* wezel) const;    // Wyœwietla wartoœæ poprzedniego elementu
    void clear();               // Czyœci ca³¹ listê, usuwaj¹c wszystkie elementy
};

#endif
