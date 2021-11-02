//162. Find Peak Element
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int start = 0, end = nums.size();
        if (end == 1)
            return 0;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid + 1 < nums.size() and nums[mid] < nums[mid + 1])
                start = mid + 1;
            else if (mid - 1 >= 0 and nums[mid] < nums[mid - 1])
                end = mid - 1;
            else
            {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};