//17. Letter Combinations of a Phone Number
class Solution
{
public:
    vector<string> ans;
    void solve(int digits, string output, string options[])
    {
        if (digits == 0)
        {
            ans.push_back(output);
            return;
        }
        int n1 = digits % 10;
        string s1 = options[n1];
        for (int i = 0; i < s1.length(); i++)
        {
            solve(digits / 10, s1[i] + output, options);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return ans;
        string output = "";
        int num = stoi(digits);
        string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(num, output, options);
        return ans;
    }
};