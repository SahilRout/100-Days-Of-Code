//Find Maximum number possible by doing at-most K swaps
class Solution
{
public:
    void solve(string str, int k, string &max)
    {
        if (k == 0)
            return;

        for (int i = 0; i < str.length() - 1; i++)
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[j] > str[i])
                {
                    swap(str[i], str[j]);
                    if (str.compare(max) > 0)
                        max = str;
                    solve(str, k - 1, max);
                    swap(str[i], str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string max = str;
        solve(str, k, max);
        return max;
    }
};