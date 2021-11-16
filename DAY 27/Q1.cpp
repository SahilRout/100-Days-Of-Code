//1497. Check If Array Pairs Are Divisible by k
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto x : arr)
            mp[(x % k + k) % k]++;
        for (auto x : arr)
        {
            int rem = (x % k + k) % k;
            if (rem == 0)
            {
                if (mp[rem] % 2 != 0)
                    return false;
            }
            else if (mp[rem] != mp[k - rem])
                return false;
        }

        return true;
    }
};