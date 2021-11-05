//The Painter's Partition Problem
class Solution
{
public:
    long long solve(int arr[], int n, long long mid)
    {
        long long sum = 0;
        long long painter = 1;
        for (long long i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                sum = arr[i];
                painter++;
            }
        }

        return painter;
    }
    long long minTime(int arr[], int n, int k)
    {
        int m = INT_MIN;
        long long sum = 0;
        for (long long i = 0; i < n; i++)
        {
            m = max(m, arr[i]);
            sum += arr[i];
        }
        long long start = m;
        long long end = sum;
        while (start < end)
        {
            long long mid = start + (end - start) / 2;
            long long painters = solve(arr, n, mid);
            if (painters <= k)
                end = mid;
            else
                start = mid + 1;
        }

        return start;
    }
};