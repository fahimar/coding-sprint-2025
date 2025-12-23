// See https://aka.ms/new-console-template for more information
// Console.WriteLine("Hello, World!");
using System;

class Program
{
    static void Main()
    {
        int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        Solution sol = new Solution();
        Console.WriteLine(sol.MaxSubArray(nums));
    }
}

public class Solution
{
    public int MaxSubArray(int[] nums)
    {
        int arraySum = nums[0];
        int total = 0;

        foreach (int i in nums)
        {
            if (total < 0)
                total = 0;

            total += i;
            arraySum = Math.Max(arraySum, total);
        }

        return arraySum;
    }
}

