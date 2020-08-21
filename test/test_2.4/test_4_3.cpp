#include <iostream>
#include <string>
using namespace std;
char * get_name();
int main()
{
    char * name;
    name = get_name();
    cout << name << "at" <<(int *)name <<endl;
    name = get_name();
    cout << name << "at" <<(int *)name <<endl;
    delete [] name;
    return 0;
}

char * get_name()
{
    char temp[80];
    cout << "Enter name:";
    cin >> temp;
    char * pn  = new char(strlen(temp)+1);
    strcpy(pn,temp);
    return pn;

}