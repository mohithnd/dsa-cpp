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

// Approach: Build a sorted portion from left to right.
// Pick the current element and shift larger elements in the
// sorted portion one position right, then insert it into the gap.
//
// Time complexity:
// Best case: O(n) — already sorted, so no shifts are needed.
// Average and worst cases: O(n²) — each element may require many shifts.
//
// Auxiliary space: O(1) — sorts in place using a few variables.
void insertion_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int ele = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > ele)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = ele;
    }
}

int main()
{
    vector<int> arr = {7, 2, 89, -3, 24, 9};

    vectorPrint(arr);

    insertion_sort(arr);

    vectorPrint(arr);

    return 0;
}