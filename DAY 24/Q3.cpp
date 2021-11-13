//451. Sort Characters By Frequency
class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, int>> hash('z' + 1, {0, 0});
        for (int i = 0; i < s.length(); i++)
            hash[s[i]] = {hash[s[i]].first + 1, s[i]};

        sort(hash.begin(), hash.end());
        string res = "";
        for (auto it : hash)
        {
            res = string(it.first, it.second) + res;
        }

        return res;
    }
};