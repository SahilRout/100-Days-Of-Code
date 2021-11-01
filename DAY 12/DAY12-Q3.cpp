//33. Search in Rotated Sorted Array
class Solution
{
public:
    int binarySearch(vector<int> &nums, int start, int end, int x)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == x)
                return mid;
            else if (x < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = 0;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] >= nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        int st;
        int en;
        if (target >= nums[mid] && target <= nums[n - 1])
        {
            st = mid;
            en = n - 1;
        }
        else
        {
            st = 0;
            en = mid - 1;
        }
        return binarySearch(nums, st, en, target);
    }
};