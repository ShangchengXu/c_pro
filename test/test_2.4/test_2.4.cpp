#include <iostream>
#include <cmath>
int main()
{
    using namespace std;
    double area;
    double side;
    cout << "Enter";
    cin >> area;
    side = sqrt(area);
    cout << "area sqrt " << side <<endl<<area;
    return 0;
}