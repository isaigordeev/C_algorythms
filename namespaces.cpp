//
// Created by Isai Gordeev on 06/02/2023.
//
#include <iostream>
#include <string>
//using namespace std;

namespace A{
    int a = 24;
    std::string b = "Isai";
}

namespace B{
    int a = 01;
    std::string b = "Gordeev";
}

using namespace A;
using namespace B;

int main(){

    std::cout << A::a << ' ' << B::b << std::endl;


    std::cout << B::a << ' ' << A::b;

    return 0;
};