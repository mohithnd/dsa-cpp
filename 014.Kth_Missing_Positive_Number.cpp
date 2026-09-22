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

int kth_missing_positive_number(vector<int> &arr, int k)
{
    int total = arr.size() + k;

    for (int i = 1; i <= total; i++)
    {
        bool is_found = false;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
            {
                is_found = true;
                break;
            }
        }

        if (is_found == false)
        {
            k--;
            if (k == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

int kth_missing_positive_number_2(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

int kth_missing_positive_number_3(vector<int> &arr, int k)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        int missing = arr[m] - (m + 1);

        if (missing < k)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return e + k + 1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    vector<int> brr = {1, 2, 3, 4};
    int l = 2;

    cout << kth_missing_positive_number(arr, k) << endl;
    cout << kth_missing_positive_number(brr, l) << endl;

    cout << endl;

    cout << kth_missing_positive_number_2(arr, k) << endl;
    cout << kth_missing_positive_number_2(brr, l) << endl;

    cout << endl;

    cout << kth_missing_positive_number_3(arr, k) << endl;
    cout << kth_missing_positive_number_3(brr, l) << endl;

    return 0;
}