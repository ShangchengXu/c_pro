#include <iostream>
#include "Student.h"
using namespace std;
template<typename T>
void selectionSort(T arr[],int n) {
    for(int i = 0; i < n; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main() {
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    float b[10] = {2.5,2.4,4,5.5,3.4,2.9,10.3,9.9,8.7,1.1};
    Student d[4] = {{"D",90},{"C",100},{"B",95},{"A",95}};
    string c[4] = {"B","v","H","O"};
    selectionSort(d,4);
    for(int i = 0; i < 4; i++) {
        cout << d[i] <<" ";
    }
    return 0;
}