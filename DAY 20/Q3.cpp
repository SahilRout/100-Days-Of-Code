//140. Word Break II
class Solution
{
public:
    vector<string> ans;
    void Solve(string s, string op, set<string> dict)
    {
        if (s.length() == 0)
        {
            op.pop_back();
            ans.push_back(op);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            string left = s.substr(0, i + 1);
            if (dict.find(left) != dict.end())
            {
                string right = s.substr(i + 1);
                Solve(right, op + left + " ", dict);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        set<string> dict;
        for (int i = 0; i < wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        Solve(s, "", dict);
        return ans;
    }
};