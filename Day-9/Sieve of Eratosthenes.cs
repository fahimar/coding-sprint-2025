using System;
using System.Collections.Generic;
using Internal;

class Solution
{
    public static List<int> SeiveOfEratosthenes(int n)
    {
        List<int> primes = new List<int>();

        if (n < 2) return primes;

        bool[] isPrime = new bool[n + 1];
        for(int i = 0; i <= n; i++)
            isPrime[i] = true;

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2; i * i <= n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
                primes.Add(i);
        }

        return primes;

    }

    static void Main()
    {
        int n = 10;
        var result = SeiveOfEratosthenes(n);

        Console.WriteLine(string.Join(", ", result));
    }
}