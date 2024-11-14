#include "ListaDwukierunkowa.h"


Wezel::Wezel(int value) : data(value), prev(nullptr), next(nullptr) {}    // Konstruktor wÍz≥a, inicjuje wartoúÊ oraz wskaüniki na NULL


ListaDwukierunkowa::ListaDwukierunkowa() : head(nullptr), tail(nullptr) {}   // Konstruktor listy, inicjuje pustπ listÍ


ListaDwukierunkowa::~ListaDwukierunkowa() {
    clear();                               // Destruktor, usuwa wszystkie elementy z listy
}


void ListaDwukierunkowa::addFront(int value) {      // Dodaje nowy element na poczπtek listy
    Wezel* newNode = new Wezel(value);
    if (head == nullptr) {                 // Jeúli lista jest pusta
        head = tail = newNode;
    }
    else {                  
        newNode->next = head;
        head->prev = newNode;              // Jeúli lista nie jest pusta
        head = newNode;
    }
}


void ListaDwukierunkowa::addBack(int value) {        // Dodaje nowy element na koniec listy
    Wezel* newNode = new Wezel(value);
    if (tail == nullptr) {                // Jeúli lista jest pusta
        head = tail = newNode;
    }
    else {                  
        newNode->prev = tail;
        tail->next = newNode;             // Jeúli lista nie jest pusta
        tail = newNode;
    }
}


void ListaDwukierunkowa::addAt(int index, int value) {         // Dodaje nowy element pod wskazanym indeksem
    if (index < 0) {
        cout << "Nieprawid≥owy indeks\n";
        return;
    }
    if (index == 0) {         
        addFront(value);              // Jeúli indeks to 0, dodaj na poczπtek
        return;
    }

    Wezel* newNode = new Wezel(value);
    Wezel* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; ++i) {  // Znajdujemy miejsce wstawienia
        current = current->next;
    }

    if (current == nullptr || current == tail) {    // Dodaj na koniec, jeúli indeks jest za duøy
        addBack(value);
    }
    else {                    
        newNode->next = current->next;
        newNode->prev = current;                              // Wstaw w úrodku listy
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
    }
}


void ListaDwukierunkowa::removeFront() {           // Usuwa element z poczπtku listy
    if (head == nullptr) return;

    Wezel* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;               // Uaktualnia wskaünik head
    else tail = nullptr;
    delete temp;
}


void ListaDwukierunkowa::removeBack() {           // Usuwa element z koÒca listy
    if (tail == nullptr) return;

    Wezel* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;              // Uaktualnia wskaünik tail
    else head = nullptr;
    delete temp;
}


void ListaDwukierunkowa::removeAt(int index) {       // Usuwa element pod wskazanym indeksem
    if (index < 0 || head == nullptr) return;
    if (index == 0) {                            // Usuwa z poczπtku listy
        removeFront();
        return;
    }

    Wezel* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {       // Znajduje element
        current = current->next;
    }

    if (current == nullptr) return;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    if (current == head) head = current->next;
    if (current == tail) tail = current->prev;
    delete current;
}



