#include <iostream>

void swap (int & a, int & b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Using main to test
int main(){
    void swap(int &a, int &b);
    int a = 3, b = 2;
    swap(a, b);
    std::cout << a << b; 
    return 0; }
