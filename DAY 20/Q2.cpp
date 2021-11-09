//526. Beautiful Arrangement
class Solution
{
public:
    int ans = 0;
    void solve(vector<int> arr, int n, int val)
    {
        if (val > n)
        {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0 && (val % i == 0 || i % val == 0))
            {
                arr[i] = val;
                solve(arr, n, val + 1);
                arr[i] = 0;
            }
        }
    }
    int countArrangement(int n)
    {
        vector<int> arr(n + 1, 0);
        solve(arr, n, 1);
        return ans;
    }
};