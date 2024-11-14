#include "ListaDwukierunkowa.h"


Wezel::Wezel(int value) : data(value), prev(nullptr), next(nullptr) {}    // Konstruktor wêz³a, inicjuje wartoœæ oraz wskaŸniki na NULL


ListaDwukierunkowa::ListaDwukierunkowa() : head(nullptr), tail(nullptr) {}   // Konstruktor listy, inicjuje pust¹ listê


ListaDwukierunkowa::~ListaDwukierunkowa() {
    clear();                               // Destruktor, usuwa wszystkie elementy z listy
}


void ListaDwukierunkowa::addFront(int value) {      // Dodaje nowy element na pocz¹tek listy
    Wezel* newNode = new Wezel(value);
    if (head == nullptr) {                 // Jeœli lista jest pusta
        head = tail = newNode;
    }
    else {                  
        newNode->next = head;
        head->prev = newNode;              // Jeœli lista nie jest pusta
        head = newNode;
    }
}


void ListaDwukierunkowa::addBack(int value) {        // Dodaje nowy element na koniec listy
    Wezel* newNode = new Wezel(value);
    if (tail == nullptr) {                // Jeœli lista jest pusta
        head = tail = newNode;
    }
    else {                  
        newNode->prev = tail;
        tail->next = newNode;             // Jeœli lista nie jest pusta
        tail = newNode;
    }
}


void ListaDwukierunkowa::addAt(int index, int value) {         // Dodaje nowy element pod wskazanym indeksem
    if (index < 0) {
        cout << "Nieprawid³owy indeks\n";
        return;
    }
    if (index == 0) {         
        addFront(value);              // Jeœli indeks to 0, dodaj na pocz¹tek
        return;
    }

    Wezel* newNode = new Wezel(value);
    Wezel* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; ++i) {  // Znajdujemy miejsce wstawienia
        current = current->next;
    }

    if (current == nullptr || current == tail) {    // Dodaj na koniec, jeœli indeks jest za du¿y
        addBack(value);
    }
    else {                    
        newNode->next = current->next;
        newNode->prev = current;                              // Wstaw w œrodku listy
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
    }
}


void ListaDwukierunkowa::removeFront() {           // Usuwa element z pocz¹tku listy
    if (head == nullptr) return;

    Wezel* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;               // Uaktualnia wskaŸnik head
    else tail = nullptr;
    delete temp;
}


void ListaDwukierunkowa::removeBack() {           // Usuwa element z koñca listy
    if (tail == nullptr) return;

    Wezel* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;              // Uaktualnia wskaŸnik tail
    else head = nullptr;
    delete temp;
}


void ListaDwukierunkowa::removeAt(int index) {       // Usuwa element pod wskazanym indeksem
    if (index < 0 || head == nullptr) return;
    if (index == 0) {                            // Usuwa z pocz¹tku listy
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

void ListaDwukierunkowa::display() const {         // Wyœwietla elementy listy od pocz¹tku do koñca
    Wezel* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void ListaDwukierunkowa::displayReverse() const {         // Wyœwietla elementy listy od koñca do pocz¹tku
    Wezel* current = tail;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}


void ListaDwukierunkowa::displayNext(Wezel* wezel) const {        // Wyœwietla nastêpny element dla danego wêz³a
    if (wezel && wezel->next) {
        cout << wezel->next->data << endl;
    }
    else {
        cout << "Brak nastêpnego elementu" << endl;
    }
}


void ListaDwukierunkowa::displayPrev(Wezel* wezel) const {        // Wyœwietla poprzedni element dla danego wêz³a
    if (wezel && wezel->prev) {
        cout << wezel->prev->data << endl;
    }
    else {
        cout << "Brak poprzedniego elementu" << endl;
    }
}


void ListaDwukierunkowa::clear() {
    while (head) {                      // Usuwa wszystkie elementy listy
        removeFront();
    }
}


