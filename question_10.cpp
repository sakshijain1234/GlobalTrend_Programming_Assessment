#include <iostream>
#include <string>
using namespace std;

// function to return answer
bool is_Alpha(string s)
{
    for (char c : s)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s;
    cout << "enter string= ";
    cin >> s;
    bool ans = is_Alpha(s);
    if (ans)
        cout << "YES ALL CHARACTERS ARE ALPBHABETIC";
    else
        cout << "NO";
    return 0;
}