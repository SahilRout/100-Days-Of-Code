//Search in an almost sorted array
class Solution
{
public:
    int binarySearch(vector<int> arr, int x)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x)
                return mid;
            if (mid > start && arr[mid - 1] == x)
                return mid - 1;
            if (mid < end && arr[mid + 1] == x)
                return mid + 1;
            if (arr[mid] > x)
                end = mid - 2;
            else
                start = mid + 2;
        }
    }
};