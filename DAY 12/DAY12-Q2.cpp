//153. Find Minimum in Rotated Sorted Array
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] >= nums[end])
                start = mid + 1;
            else
                end = mid;
        }

        return nums[mid];
    }
};