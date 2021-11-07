//90. Subsets II
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int> &arr, vector<int> ds)
    {
        ans.push_back(ds);
        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            ds.push_back(arr[i]);
            solve(i + 1, arr, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        solve(0, nums, ds);
        return ans;
    }
};