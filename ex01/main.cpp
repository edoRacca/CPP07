
#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void printElem(const T& elem) {
    std::cout << elem << " ";
}

// Funzione che raddoppia un numero (non-const reference)
void doubleElem(int& elem) {
    elem *= 2;
}

// Funzione che aggiunge un punto esclamativo a una stringa (non-const reference)
void addExclamation(std::string& elem) {
    elem += "!";
}

// ======================
// MAIN DI TEST
// ======================
int main() {
    {
        std::cout << "=== Test con int ===\n";
        int arr[] = {1, 2, 3, 4, 5};
        size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Array iniziale: ";
        iter(arr, len, printElem<int>);
        std::cout << "\n";

        iter(arr, len, doubleElem);

        std::cout << "Dopo doubleElem: ";
        iter(arr, len, printElem<int>);
        std::cout << "\n\n";
    }

    {
        std::cout << "=== Test con string ===\n";
        std::string words[] = {"ciao", "mondo", "iter"};
        size_t len = sizeof(words) / sizeof(words[0]);

        std::cout << "Array iniziale: ";
        iter(words, len, printElem<std::string>);
        std::cout << "\n";

        iter(words, len, addExclamation);

        std::cout << "Dopo addExclamation: ";
        iter(words, len, printElem<std::string>);
        std::cout << "\n\n";
    }

    {
        std::cout << "=== Test con const array ===\n";
        const int constArr[] = {42, 1337, 7};
        size_t len = sizeof(constArr) / sizeof(constArr[0]);

        std::cout << "Stampa di un array const: ";
        iter(constArr, len, printElem<int>);
        std::cout << "\n\n";
    }

    return 0;
}