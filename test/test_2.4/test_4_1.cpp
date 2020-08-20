#include <iostream>
#include <string>
 int main()
 {
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;
    string str_1 = "sadsads";
    string str_2 = "zxczczx";
    cout << str_1 + str_2 << sizeof str_1;
    struct flexible
    {
        char name[20];
        string str;
        double price;
    };
    int yamcost[3] = {20,10,5};
    cout << "total yams = " << yams[0] + yams[1] + yams[2] <<endl;
    cout << yamcost[1]*yams[1] + yamcost[0]*yams[0] + yamcost[2]*yams[2];
    cout << endl << sizeof yams << endl << sizeof yamcost;
    return 0;
 }