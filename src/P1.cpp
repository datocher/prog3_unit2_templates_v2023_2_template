//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "P1.h"
using namespace std;

int main() {
    auto text = input();
    auto entero = input<int>("Ingrese un numero: ");
    auto real = input<double>("Ingrese un numero: ");
    
    std::cout << "El texto es: " << text << std::endl;
    std::cout << "El entero es: " << entero << std::endl;
    std::cout << "El real es: " << real << std::endl;

    return 0;
}
