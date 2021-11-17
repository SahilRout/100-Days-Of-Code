//781. Rabbits in Forest
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int count = 0;
        int n = answers.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp[answers[i]] == 0)
            {
                count += answers[i] + 1;
                mp[answers[i]] = answers[i] + 1;
            }
            mp[answers[i]]--;
        }

        return count;
    }
};