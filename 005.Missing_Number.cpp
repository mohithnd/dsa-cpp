#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Approach 1: Brute force.
// For each number from 0 to n, search the array for that number.
// Return the first number that is not found.
//
// Time complexity: O(n²) worst case — O(n) searches, each taking O(n).
// Auxiliary space: O(1) — only loop variables and a boolean flag.
int missing_number(vector<int> &arr)
{
    for (int i = 0; i <= arr.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            return i;
        }
    }
    return -1;
}

// Approach 2: Expected sum minus actual sum.
// Calculate the sum of all numbers from 0 to n.
// Subtract the sum of the array elements to find the missing number.
//
// Time complexity: O(n) — two sequential loops, O(n) + O(n) = O(n).
// Auxiliary space: O(1) — only two sums and loop variables.
int missing_number_2(vector<int> &arr)
{
    long long expSum = 0;
    for (int i = 0; i <= arr.size(); i++)
    {
        expSum += i;
    }
    long long curr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
    }
    return expSum - curr;
}

// Approach 3: XOR cancellation.
// XOR all numbers from 0 to n and all array elements.
// Matching values cancel because x ^ x = 0.
// Only the missing number remains because x ^ 0 = x.
//
// Time complexity: O(n) — two sequential loops.
// Auxiliary space: O(1) — only an accumulator and loop variables.
int missing_number_3(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i <= arr.size(); i++)
    {
        ans = ans ^ i;
    }
    long long curr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    cout << missing_number(arr) << endl;

    cout << missing_number_2(arr) << endl;

    cout << missing_number_3(arr) << endl;

    return 0;
}