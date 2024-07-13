#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_difference(vector<int> &nums, int n)
{
    if (n < 2)
        return 0;
    int mini = nums[0], maxi = nums[0];
    for (int i = 1; i < n; i++)
    {
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }
    return maxi - mini;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "maximum difference is= " << max_difference(nums, n);

    return 0;
}