//974. Subarray Sums Divisible by K
class Solution
{
public:
    int subarraysDivByK(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        mp[0]++;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (mp.count(rem) > 0)
                ans += mp[rem];
            mp[rem]++;
        }

        return ans;
    }
};
