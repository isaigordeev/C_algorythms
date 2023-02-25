//
// Created by Isai Gordeev on 06/02/2023.
//
#include <iostream>
using namespace std;


int add(int a, int b){
    return a + b;
}

int substract(int a, int b){
    return a - b;
}

int doubling(int (*ptr)(int, int), int a, int b){
    int result1 = (*ptr)(a, b);
    int result2 = (*ptr)(a, result1);

    return result2;
}

void increment(int &a){
    ++a;
}

int main(){
    int x = 5;
    int &a = x;
    int (*ptr_add)(int, int) = add;

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    cout << arr << ' ' << *arr << endl;
    int n = size(arr);

    for (int i=0; i < n; increment(i))
        cout << arr[i] << " ";

//    int result = (*ptr_add)(2,3);
//    cout << result;

//    int result = doubling(add, 2, 3);
//    cout << result;



//    cout << a << endl;
//    cout << x << endl;
//    cout << &a << endl;

//    a = 10;
//    cout << "Changement" << endl;
//    cout << a << endl;
//    cout << x << endl;
//    cout << &a << endl;
//    x = 11;
//    cout << "Changement" << endl;
//    cout << a << endl;
//    cout << x << endl;
//    cout << &a << endl;
//    int &b = x;
//
//    cout << a << endl;
//    cout << b << endl;
//    cout << x << endl;
//    cout << &a << endl;
//    cout << &b << endl;
//
//    b = 15;
//
//    cout << a << endl;
//    cout << b << endl;
//    cout << x << endl;
//    cout << &a << endl;
//    cout << &b << endl;


//    int *ptr1 = &x;
//    int *ptr2 = &a;
//    int *ptr3 = ptr1;
//
//    cout << ptr1 << endl;
//    cout << ptr2 << endl;
//    cout << *ptr1 << ' ' << *ptr2 << endl;
//
//    *ptr1 = 6;
//
//    cout << ptr1 << endl;
//    cout << ptr2 << endl;
//    cout << *ptr1 << ' ' << *ptr2 << endl;
//
//    *ptr2 = 7;
//
//    cout << ptr1 << endl;
//    cout << ptr2 << endl;
//    cout << ptr3 << endl;
//    cout << *ptr1 << ' ' << *ptr2 << endl;


    return 0;
}
