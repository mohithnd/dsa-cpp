#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Approach: Calculate the hours needed at the given eating rate.
// Each pile needs ceil(bananas / rate) hours because Koko cannot
// move to another pile during the same hour.
// Return true if the total hours do not exceed h.
//
// Requires rate >= 1.
// Time complexity: O(n).
// Auxiliary space: O(1).
bool check(vector<int> &piles, int h, int rate)
{
    long long hours = 0;

    for (int bananas : piles)
    {
        hours += bananas / rate;

        if (bananas % rate != 0)
        {
            hours++;
        }
    }

    return hours <= h;
}

// Approach: Try every eating rate from 1 to the largest pile.
// Return the first rate that finishes all piles within h hours.
//
// Let M = largest pile size.
// Time complexity: O(n * M) worst case.
// Auxiliary space: O(1).
int koko_eating_bananas(vector<int> &piles, int h)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    for (long long rate = 1; rate <= maxPile; rate++)
    {
        if (check(piles, h, static_cast<int>(rate)))
        {
            return static_cast<int>(rate);
        }
    }

    return -1;
}

// Approach: Binary-search the eating rate between 1 and the largest pile.
// If a rate works, save it and try smaller rates.
// Otherwise, try larger rates.
// Increasing the rate never increases the required hours.
//
// Let M = largest pile size.
// Time complexity: O(n * log(M + 1)).
// Auxiliary space: O(1).
int koko_eating_bananas_2(vector<int> &piles, int h)
{
    long long s = 1;
    long long e = *max_element(piles.begin(), piles.end());
    int ans = -1;

    while (s <= e)
    {
        int m = static_cast<int>(s + (e - s) / 2);

        if (check(piles, h, m))
        {
            ans = m;
            e = 1LL * m - 1;
        }
        else
        {
            s = 1LL * m + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;

    cout << koko_eating_bananas(piles, h) << endl;
    cout << koko_eating_bananas(piles2, h2) << endl;
    cout << koko_eating_bananas(piles3, h3) << endl;

    cout << endl;

    cout << koko_eating_bananas_2(piles, h) << endl;
    cout << koko_eating_bananas_2(piles2, h2) << endl;
    cout << koko_eating_bananas_2(piles3, h3) << endl;

    return 0;
}