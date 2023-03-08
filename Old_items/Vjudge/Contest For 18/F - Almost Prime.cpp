#include<bits/stdc++.h>
#include<vector>
using namespace std;

int prime(int n)
{
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;
    for(int i = 3; i * i <= n; i+= 2)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int prime_count, aprime_count = 0, n;
    vector <int> num;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        prime_count = 0;
        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                if(j != i / j)
                {
                    num.push_back(j);
                    num.push_back(i / j);
                }
                else
                    num.push_back(j);
            }
        }
        for(int j = 0; j < num.size(); j++)
        {
            if(prime(num[j]) == 1)
                prime_count++;
        }
        if(prime_count == 2)
            aprime_count++;
        num.clear();
    }

    printf("%d\n", aprime_count);

    return 0;
}
