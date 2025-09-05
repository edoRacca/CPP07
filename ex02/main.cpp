
#include "Array.hpp"

#include <iostream>
#include <string>

int main()
{
	try {
        
        std::cout << "=== Test costruttore vuoto ===" << std::endl;
        Array<int> a1;
        std::cout << "Dimensione a1: " << a1.size() << std::endl;

        std::cout << "\n=== Test costruttore con n ===" << std::endl;
        Array<int> a2(5);
        std::cout << "Dimensione a2: " << a2.size() << std::endl;
        for (unsigned int i = 0; i < a2.size(); i++) {
            std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
        }

        std::cout << "\n=== Test assegnazione valori ===" << std::endl;
        for (unsigned int i = 0; i < a2.size(); i++) {
            a2[i] = i * 10;
        }
        for (unsigned int i = 0; i < a2.size(); i++) {
            std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
        }

        std::cout << "\n=== Test copy constructor ===" << std::endl;
        Array<int> a3(a2);
        std::cout << "Modifico a2[0] = 999" << std::endl;
        a2[0] = 999;
        std::cout << "a2[0] = " << a2[0] << std::endl;
        std::cout << "a3[0] (copiato prima) = " << a3[0] << std::endl;

        std::cout << "\n=== Test operatore di assegnazione ===" << std::endl;
        Array<int> a4;
        a4 = a2;
        std::cout << "Modifico a2[1] = 777" << std::endl;
        a2[1] = 777;
        std::cout << "a2[1] = " << a2[1] << std::endl;
        std::cout << "a4[1] (copiato prima) = " << a4[1] << std::endl;

        std::cout << "\n=== Test eccezione fuori indice ===" << std::endl;
        std::cout << "Provo a2[10]..." << std::endl;
        std::cout << a2[10] << std::endl;  // Deve lanciare eccezione

    } catch (const std::exception &e) {
        std::cerr << "Eccezione catturata: " << e.what() << std::endl;
    }

}