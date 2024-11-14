/// @file main.cpp Główny plik wywołujący
#include "ListaDwukierunkowa.h"
///@brief Funkcja main
int main() {
    ListaDwukierunkowa list;

list.addFront(1);      ///< Dodaje 1 na początek
list.addBack(2);       ///< Dodaje 2 na koniec
list.addBack(3);       ///< Dodaje 3 na koniec
list.addAt(1, 4);      ///< Dodaje 4 pod indeks 1

cout << "Lista: ";
list.display();        ///< Wyświetla listę od początku

cout << "Lista w odwrotnej kolejności: ";
list.displayReverse(); ///< Wyświetla listę od końca

list.removeFront();    ///< Usuwa pierwszy element
cout << "Po usunieciu z poczatku: ";
list.display();

list.removeBack();     ///< Usuwa ostatni element
cout << "Po usunieciu z końca: ";
list.display();

list.removeAt(1);      ///< Usuwa element pod indeksem 1
cout << "Po usunieciu indeksu 1: ";
list.display();

list.clear();          ///< Czyści całą listę
cout << "Po wyczyszczeniu listy: ";
list.display();

    return 0;
}
