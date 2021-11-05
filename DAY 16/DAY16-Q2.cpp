//1011. Capacity To Ship Packages Within D Days
class Solution
{
public:
    bool solve(vector<int> &weights, int days, int mid)
    {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (sum > mid)
            {
                cnt++;
                sum = weights[i];
            }
        }
        if (cnt <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            start = max(start, weights[i]);
            end += weights[i];
        }
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (solve(weights, days, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};