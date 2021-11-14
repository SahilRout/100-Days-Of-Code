//3. Longest Substring Without Repeating Characters
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1);
        int l = 0, r = 0;
        int n = s.size();
        int ans = 0;
        while (r < n)
        {
            if (mp[s[r]] != -1)
            {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            int window_size = r - l + 1;
            ans = max(ans, window_size);
            r++;
        }

        return ans;
    }
};