//131. Palindrome Partitioning
class Solution
{
public:
    vector<vector<string>> ans;
    void solve(int ind, string s, vector<string> row)
    {
        if (ind == s.size())
        {
            ans.push_back(row);
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                row.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, row);
                row.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st++] != s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> row;
        solve(0, s, row);
        return ans;
    }
};