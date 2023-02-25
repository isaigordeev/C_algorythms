//
// Created by Isai Gordeev on 08/02/2023.
//
#include <iostream>
using namespace std;

void swap_(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    cout << arr << ' ' << *arr << endl;
    int n = sizeof(arr) / sizeof(arr[0]);

    int a = 1, b = 2;
    cout << a << ' ' << b << endl;
    swap_(a, b);
    cout << a << ' ' << b;

    return 0;

}