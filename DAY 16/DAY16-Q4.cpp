//1760. Minimum Limit of Balls in a Bag
class Solution
{
public:
    bool solve(vector<int> &nums, int mid, int maxOperations)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            maxOperations -= (nums[i] / mid);
            if (nums[i] % mid == 0)
                maxOperations++;
        }
        return maxOperations >= 0;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int start = 1;
        int ans = 0;
        int end = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            end = max(end, nums[i]);
        }
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (solve(nums, mid, maxOperations))
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