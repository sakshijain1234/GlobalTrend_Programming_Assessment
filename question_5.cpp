#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




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
    int k;
    cout << "Enter the K: ";
    cin >> k;

    rotate(nums, n, k);

    cout << "after rotating the array by k elements to the right= " << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << " "; // Output the elements of the vector
    }
    cout << endl;

    return 0;
}
