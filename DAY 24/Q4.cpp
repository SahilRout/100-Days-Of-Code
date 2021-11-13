//438. Find All Anagrams in a String
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        vector<int> phash(26, 0);
        vector<int> hash(26, 0);
        int window = p.length();
        int n = s.length();
        if (n < window)
            return ans;
        int l = 0, r = 0;
        while (r < window)
        {
            phash[p[r] - 'a']++;
            hash[s[r++] - 'a']++;
        }
        r--;
        while (r < n)
        {
            if (phash == hash)
                ans.push_back(l);
            r++;
            if (r != n)
                hash[s[r] - 'a']++;

            hash[s[l] - 'a']--;
            l++;
        }
        return ans;
    }
};