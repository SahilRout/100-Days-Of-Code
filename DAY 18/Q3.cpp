//Combination Sum II
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int ind, int target, vector<int> &arr, vector<int> ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++)
        {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        solve(0, target, candidates, ds);
        return ans;
    }
};