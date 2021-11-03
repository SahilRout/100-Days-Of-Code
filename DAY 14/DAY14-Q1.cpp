//Maximum Element in a Bitonic Array
class Solution
{
public:
    int SolveBinarySearch(vector<int> arr)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
                return mid;
            else if (arr[mid] < arr[mid - 1])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};