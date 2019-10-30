#include <iostream>
using namespace std;

int main()
{
    int a1, a2, a3;
    while(cin >> a1 >> a2 >> a3 && !(a1 == 0 && a2 == 0 && a3 == 0))
    {
        int d = a3 - a2;
        if(d == (a2 - a1))
            cout << "AP " << a3 + d << endl;
        else
        {
            int r = a3/a2;
            cout << "GP " << a3 * r << endl;
        }
    }
    return 0;
}
