#include <iostream>
#include <unordered_map>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    string S;
    cout << "Enter a string: ";
    cin >> S;
    cout << longestSubstrDistinctChars(S) << endl;
}

int longestSubstrDistinctChars(string S)
{
    int n = S.length();
    if (n == 1)
        return 1;
    unordered_map<char, int> mapper;
    int start = 0, end = 0;
    int ans = 0;
    for (; end < n; end++)
    {
        if (mapper.find(S[end]) != mapper.end())
        {
            start = max(start, mapper[S[end]] + 1);
        }
        mapper[S[end]] = end;
        ans = max(ans, end - start + 1);
    }
    return ans;
}