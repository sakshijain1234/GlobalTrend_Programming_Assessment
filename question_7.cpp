#include <iostream>
using namespace std;

int sumOfDigits(int N)
{
    int sum = 0;
    while (N > 0)
    {
        int rem = N % 10;
        sum += rem;
        N /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cout << "enter a number= " << endl;
    cin >> n;
    cout << "sum of digits are= " << sumOfDigits(n);
}