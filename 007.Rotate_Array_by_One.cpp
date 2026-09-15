#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void vectorPrint(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;
}

// Approach: Rotate the array one position to the right.
// Save the last element, then shift the remaining elements right.
// Traverse backwards to avoid overwriting values before copying them.
// Place the saved last element at index 0.
//
// Time complexity: O(n) — shifts n - 1 elements.
// Auxiliary space: O(1) — uses only a temporary value and loop variable.
void rotate_array_by_one(vector<int> &arr)
{
    int last = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vectorPrint(arr);

    rotate_array_by_one(arr);

    vectorPrint(arr);
    return 0;
}