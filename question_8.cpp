#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

int main()
{
    int a, b;
    cout << "enter A= ";
    cin >> a;
    cout << "enter B= ";
    cin >> b;
    cout << "GCD is= " << GCD(a, b);
}