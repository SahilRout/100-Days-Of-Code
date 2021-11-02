//744. Find Smallest Letter Greater Than Target
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int start = 0;
        int end = n - 1;
        char ans = letters[0];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (letters[mid] == target)
                start = mid + 1;
            else if (letters[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                ans = letters[mid];
                end = mid - 1;
            }
        }
        return ans;
    }
};