#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, a, b, test, result;
    char sign;

    cin >> test;

    for(i = 1; i <= test; i++)
    {
        scanf("%lld %lld %c", &a, &b, &sign);

        if(sign == '+')
            result = a + b;
        else if(sign == '-')
            result = a - b;
        else if(sign == '*')
            result = a * b;
        else if(sign == '/')
            result = a / b;
        else if(sign == '%')
            result = a % b;


        printf("Case %d: ", i);
        cout << result << endl;
    }

    return 0;
}

