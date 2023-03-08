#include<bits/stdc++.h>
using namespace std;

unsigned long long int facto (unsigned long long int a)
{
    unsigned long long int i, j, k = 1;
    for(i = 2; i <= a; i++)
        k *= i;
    return k;
}

int main()
{
    unsigned long long i, j, n, m, t, c, fact;

    scanf("%llu", &t);

    while(t--)
    {
        scanf("%llu %llu %llu", &n, &m, &c);
        cout << facto(n) << endl;;
    }

}
