#include <iostream>
#include <print>
#include <string>
#include "sort.hpp"

int main()
{
    // get the values
    std::string s1, s2;
    std::print("Enter first string: ");
    std::getline(std::cin, s1);
    std::print("Enter second string: ");
    std::getline(std::cin, s2);

    const char* p1 = s1.c_str();
    const char* p2 = s2.c_str();

    float f1, f2;
    std::print("Enter two floats: ");
    std::cin >> f1 >> f2;

    int i1, i2, i3;
    std::print("Enter three integers: ");
    std::cin >> i1 >> i2 >> i3;

    // sort everything
    std::println("== SORTED ==");

    Sort2(s1, s2);
    std::println("std::string: {} {}", s1, s2);

    Sort2(p1, p2);
    std::println("const char*: {} {}", p1, p2);

    Sort2(f1, f2);
    std::println("float: {} {}", f1, f2);


    Sort2(i1, i2);
    Sort2(i2, i3);
    Sort2(i1, i2);
    std::println("int: {} {} {}", i1, i2, i3);
}
