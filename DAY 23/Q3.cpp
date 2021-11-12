//Count distinct elements in every window
class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            if (mp[arr[i]] == 0)
            {
                count++;
            }
            mp[arr[i]]++;
        }
        ans.push_back(count);
        for (int i = k; i < n; i++)
        {
            if (mp[arr[i - k]] == 1)
            {
                count--; // we check if the prev element just occured once
            }
            mp[arr[i - k]]--;
            if (mp[arr[i]] == 0)
            {
                count++;
            }
            mp[arr[i]]++;
            ans.push_back(count);
        }

        return ans;
    }
};