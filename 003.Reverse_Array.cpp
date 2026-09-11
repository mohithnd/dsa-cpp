#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using an extra array.
// Traverse the original array backwards and store elements in copy.
// Copy those elements back into the original array.
//
// Time complexity: O(n) — two sequential traversals.
// Auxiliary space: O(n) — copy stores n elements.
void reverse_array(vector<int> &arr)
{
    vector<int> copy;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        copy.push_back(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = copy[i];
    }
}

// Approach 2: Two pointers.
// Start at the first and last elements.
// Swap them and move both pointers inward until they meet or cross.
//
// Time complexity: O(n) — performs floor(n / 2) swaps.
// Auxiliary space: O(1) — only two indices and swap's temporary storage.
void reverse_array_2(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    vector<int> arr = {12, 3, 15, 7, 9};
    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;

    reverse_array(arr);

    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;

    reverse_array_2(arr);

    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;

    return 0;
}