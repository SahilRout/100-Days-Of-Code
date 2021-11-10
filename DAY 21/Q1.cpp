//301. Remove Invalid Parentheses
class Solution
{
public:
    vector<string> ans;
    int removeMin(string str)
    {
        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (ch == '(')
                st.push(ch);
            else if (ch == ')')
            {
                if (st.size() == 0)
                    st.push(ch);
                else if (st.top() == ')')
                    st.push(ch);
                else if (st.top() == '(')
                    st.pop();
            }
        }

        return st.size();
    }
    void solve(string str, int minR, set<string> &myset)
    {
        if (minR == 0)
        {
            if (myset.find(str) == myset.end())
            {
                if (removeMin(str) == 0)
                {
                    ans.push_back(str);
                    myset.insert(str);
                }
            }
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            string left = str.substr(0, i);
            string right = str.substr(i + 1);
            solve(left + right, minR - 1, myset);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        set<string> myset;
        int minR = removeMin(s);
        solve(s, minR, myset);
        return ans;
    }
};