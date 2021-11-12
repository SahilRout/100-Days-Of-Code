//560. Subarray Sum Equals K
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;

        unordered_map<int, int> mp;
        int currSum = 0;
        int i = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            if (currSum == k)
                count++;

            if (mp.find(currSum - k) != mp.end())
                count += mp[currSum - k];

            mp[currSum]++;
        }

        return count;
    }
};