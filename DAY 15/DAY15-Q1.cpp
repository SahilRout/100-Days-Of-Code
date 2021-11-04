//Allocate minimum number of pages
class Solution
{
public:
    int solve(int A[], int pages, int M, int N)
    {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (sum + A[i] > pages)
            {
                cnt++;
                sum = A[i];
                if (sum > pages)
                    return false;
            }
            else
            {
                sum += A[i];
            }
        }
        if (cnt < M)
            return true;
        return false;
    }
    int findPages(int A[], int N, int M)
    {
        if (M > N)
            return -1;
        int low = A[0];
        int high = 0;
        for (int i = 0; i < N; i++)
        {
            high = high + A[i];
            low = min(low, A[i]);
        }
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (solve(A, mid, M, N))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};