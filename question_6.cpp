#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    int temp = 1;
    for (int i = 2; i <= n; i++)
    {
        temp *= i;
    }
    return temp;
}

int main()
{
    int n;
    cout << "enter a number to find a factorial: " << endl;
    cin >> n;
    int ans = factorial(n);
    cout << "factorial of " << n << " is: " << ans;
    return 0;
}