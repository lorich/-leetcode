class Solution
{
  public:
    int helper(int m, int n)
    {
        if(m < 1 or n < 1) 
            return 0;
        if (
            (1 == m and 1 == n) or
            (1 == m and 2 == n) or
            (2 == m and 1 == n))
        {
            return 1;
        }
        return helper(m-1, n) + helper(m, n-1);
    }
    int uniquePaths(int m, int n)
    {
        return helper(m, n);
    }
};
