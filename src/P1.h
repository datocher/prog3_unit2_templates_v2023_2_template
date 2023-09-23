//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2023_2_P1_H
#define PROG3_UNIT2_TEMPLATES_V2023_2_P1_H
#include <string>

template <typename T = std::string>
T input(const std::string& message = "") {
    std::cout << message;
    T value;
    std::cin >> value;
    return value;
}
#endif //PROG3_UNIT2_TEMPLATES_V2023_2_P1_H
