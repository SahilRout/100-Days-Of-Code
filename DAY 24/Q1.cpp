//525. Contiguous Array
class Solution
{
public:
    int findMaxLength(vector<int> &arr)
    {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i] == 0 ? -1 : 1;
            if (sum == 0)
            {
                if (ans < i + 1)
                    ans = i + 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                if (ans < i - mp[sum])
                    ans = i - mp[sum];
            }
            else
                mp[sum] = i;
        }

        return ans;
    }
};