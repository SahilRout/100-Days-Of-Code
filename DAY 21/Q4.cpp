//47. Permutations II
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> nums, int k, int n)
    {
        if (k == n - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = k; i < n; i++)
        {
            if (i != k && nums[i] == nums[k])
                continue; // duplicate element
            swap(nums[i], nums[k]);
            solve(nums, k + 1, n);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        solve(nums, 0, nums.size());
        return ans;
    }
};
