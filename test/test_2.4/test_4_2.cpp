#include <iostream>
#include <string>
#include <cstring>
int main()
{
    using namespace std;
    int * pt = new int[3];
    short * ps = new short[10];
    
    char a[20] = "asdadsadsad";
    char * str_1 = new char[strlen(a)+1];
    strcpy(str_1,a);
    delete [] pt;
    delete [] ps;
    pt[0] = 10;
    pt[1] = 21;
    pt[2] = 22;
    cout << pt << pt[0] << endl << pt[1] << endl << str_1;
    delete [] str_1;

    return 0;




}