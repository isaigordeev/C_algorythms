#include <iostream>
using namespace std;



int main() {
    int i = 0, j = 0;
    while (i < 5 && j < 5){
        cout << i << ' ' << j <<endl;
        ++i;
        j += 2;
    }
    return 0;
}
