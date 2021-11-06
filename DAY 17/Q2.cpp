//Aggressive cows
#include <bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int cows, int mid)
{
    int cnt = 1;
    int lastPlaced = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastPlaced >= mid)
        {
            cnt++;
            lastPlaced = arr[i];
        }
    }
    if (cnt >= cows)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cows;
        cin >> n >> cows;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int start = 1;
        int end = arr[n - 1] - arr[0];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (solve(arr, n, cows, mid))
                start = mid + 1;
            else
                end = mid - 1;
        }
        cout << end << endl;
    }

    return 0;
}