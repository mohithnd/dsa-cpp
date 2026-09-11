#include <iostream>
#include <vector>
using namespace std;

// Approach: Linear search.
// Check elements from left to right.
// Return the index of the first match, or -1 if not found.
//
// Time complexity (search logic):
// Best case: O(1) — target is the first element.
// Average/Worst case: O(n) — may check all elements.
//
// Auxiliary space (search logic only): O(1).
// Uses only a loop variable; no additional data structure.
// These complexities exclude the pass-by-value parameter copy.
int array_search(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {12, 3, 15, 7, 9};
    int ans1 = array_search(arr, 8);
    cout << ans1 << endl;
    int ans2 = array_search(arr, 7);
    cout << ans2 << endl;
    return 0;
}