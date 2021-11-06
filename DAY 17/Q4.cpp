//912. Sort an Array
class Solution
{
public:
    void Insertion(vector<int> &arr, int x)
    {
        if (arr.size() == 0 || arr[arr.size() - 1] <= x)
        {
            arr.push_back(x);
            return;
        }
        int temp = arr[arr.size() - 1];
        arr.pop_back();
        Insertion(arr, x);
        arr.push_back(temp);
    }
    void Sorting(vector<int> &arr)
    {
        if (arr.size() <= 1)
            return;
        int x = arr[arr.size() - 1];
        arr.pop_back();
        Sorting(arr);
        Insertion(arr, x);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        Sorting(nums);
        return nums;
    }
};