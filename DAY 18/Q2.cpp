//39. Combination Sum
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr, int target, int ind, vector<int> ds)
    {
        if (ind == arr.size())
        {
            if (target == 0)
                ans.push_back(ds);

            return;
        }

        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            solve(arr, target - arr[ind], ind, ds);
            ds.pop_back();
        }
        solve(arr, target, ind + 1, ds);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ds;
        solve(candidates, target, 0, ds);
        return ans;
    }
};