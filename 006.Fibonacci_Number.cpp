#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Approach 1: Store Fibonacci values in an array.
// Start with F(0) = 0 and F(1) = 1.
// Calculate each next value using the previous two.
//
// Time complexity: O(n) — calculate values from 2 through n.
// Auxiliary space: O(1) for this fixed-size array of 100 elements.
// If the array were sized to n + 1, auxiliary space would be O(n).
int fibonacchi(int n)
{
    int arr[100] = {0};
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

// Approach 2: Recursion.
// F(n) = F(n - 1) + F(n - 2), with F(0) = 0 and F(1) = 1.
// Repeatedly calculate smaller Fibonacci values.
//
// Time complexity: O(2^n) — exponential due to repeated calculations.
// Auxiliary space: O(n) — maximum depth of the recursive call stack.
int fibonacchi_2(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacchi_2(n - 1) + fibonacchi_2(n - 2);
}

int main()
{
    cout << fibonacchi(10) << endl;
    cout << fibonacchi_2(10) << endl;

    cout << fibonacchi(15) << endl;
    cout << fibonacchi_2(15) << endl;
    return 0;
}