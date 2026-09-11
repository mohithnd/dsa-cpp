#include <iostream>
#include <vector>
using namespace std;

// Approach: Find minimum and maximum in a single traversal.
// Initialize both with the first element, then scan the remaining
// elements, updating ans[0] (minimum) and ans[1] (maximum).
// Assumes the array is non-empty.
//
// Time complexity (logic only): O(n) in all cases.
// Every element is processed to find the minimum and maximum.
//
// Auxiliary space (logic only): O(1).
// Uses a fixed-size result vector of two elements and a loop variable.
// Excludes the input array and the pass-by-value parameter copy.
vector<int> min_and_max(vector<int> arr)
{
    vector<int> ans = {arr[0], arr[0]};

    for (int i = 1; i < arr.size(); i++)
    {
        ans[0] = min(ans[0], arr[i]);
        ans[1] = max(ans[1], arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {12, 3, 15, 7, 9};
    vector<int> ans = min_and_max(arr);
    for (int i : ans)
    {
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}