//336. Palindrome Pairs
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        int n = words.size();
        if (n < 2)
            return ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            auto s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= words[i].size(); j++)
            {
                string s1 = words[i].substr(0, j);
                string s2 = words[i].substr(j);
                if (mp.count(s1) && isPalindrome(s2) && mp[s1] != i)
                {
                    ans.push_back({i, mp[s1]});
                }
                if (!s1.empty() && mp.count(s2) && isPalindrome(s1) && mp[s2] != i)
                {
                    ans.push_back({mp[s2], i});
                }
            }
        }

        return ans;
    }
};