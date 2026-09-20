#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void vectorPrint(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << "  ";
    }
    cout << endl;
}

int search_insert_position(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target)
        {
            return i;
        }
    }
    return arr.size();
}

int search_insert_position_2(vector<int> &arr, int target)
{
    int ans = arr.size();

    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (target == arr[m])
        {
            ans = m;
            e = m - 1;
        }
        else if (target < arr[m])
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};

    cout << search_insert_position(arr, 5) << endl;
    cout << search_insert_position(arr, 2) << endl;
    cout << search_insert_position(arr, 7) << endl;

    cout << endl;

    cout << search_insert_position_2(arr, 5) << endl;
    cout << search_insert_position_2(arr, 2) << endl;
    cout << search_insert_position_2(arr, 7) << endl;

    return 0;
}