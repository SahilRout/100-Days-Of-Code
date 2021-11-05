//50. Pow(x, n)
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return 1;
        if (n == 1)
            return x;
        else if (n == -1)
            return 1 / x;

        double pow = myPow(x, n / 2);
        double base = (n > 0) ? x : 1 / x;
        if (n % 2 == 0)
            return pow * pow;
        else
            return pow * pow * base;
    }
};