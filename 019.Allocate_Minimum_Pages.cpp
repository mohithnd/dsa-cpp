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

// Approach: Assign consecutive books to the current student
// while their total stays within limit. Otherwise, start a new student.
// Using at most k students is feasible: groups can be split further
// to reach exactly k students, provided k <= arr.size().
//
// Time complexity: O(n).
// Auxiliary space: O(1).
bool check(vector<int> &arr, int k, long long limit)
{
    int allocated = 1;
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= limit)
        {
            sum += arr[i];
        }
        else
        {
            allocated++;
            sum = arr[i];
        }
    }

    return allocated <= k;
}

// Approach: Try every page limit from the largest book to the total
// pages. Return the first limit that allows allocation to at most
// k students, since this is the smallest feasible limit.
//
// Let R = total pages - largest book + 1.
// Time complexity: O(n * R).
// Auxiliary space: O(1).
int allocate_minimum_pages(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }
    long long minLimit = 0;
    long long maxLimit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > minLimit)
        {
            minLimit = arr[i];
        }
        maxLimit += arr[i];
    }
    for (long long i = minLimit; i <= maxLimit; i++)
    {
        if (check(arr, k, i))
        {
            return (int)i;
        }
    }
    return -1;
}

// Approach: Binary-search the page limit between the largest book
// and the total pages. If a limit works, save it and search smaller
// limits. Otherwise, search larger limits.
//
// Let R = total pages - largest book + 1.
// Time complexity: O(n * log(R + 1)).
// Auxiliary space: O(1).
int allocate_minimum_pages_2(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }
    long long s = 0;
    long long e = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > s)
        {
            s = arr[i];
        }
        e += arr[i];
    }
    long long ans = -1;
    while (s <= e)
    {
        long long m = s + (e - s) / 2;
        if (check(arr, k, m))
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
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    vector<int> brr = {15, 17, 20};
    int l = 5;

    cout << allocate_minimum_pages(arr, k) << endl;
    cout << allocate_minimum_pages(brr, l) << endl;
    cout << endl;

    cout << allocate_minimum_pages_2(arr, k) << endl;
    cout << allocate_minimum_pages_2(brr, l) << endl;
    cout << endl;

    return 0;
}