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

// Approach: For each position, find the smallest element in the
// remaining unsorted portion and swap it into that position.
// After each pass, one more element is in its correct position.
//
// Time complexity: O(n²) in best, average, and worst cases.
// The remaining elements are scanned even if the array is already sorted.
//
// Auxiliary space: O(1) — only a few variables are used.
// The array is passed by reference and sorted in place.
void selection_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {7, 2, 89, -3, 24, 9};

    vectorPrint(arr);

    selection_sort(arr);

    vectorPrint(arr);

    return 0;
}