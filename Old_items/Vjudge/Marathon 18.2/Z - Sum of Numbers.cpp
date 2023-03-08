#include<bits/stdc++.h>

using namespace std;

int digit_sum(char n[])
{
    int sum = 0;
    for(int i = 0; n[i] != '\0'; i++)
        sum += (n[i] - '0');

    return sum;
}

int main()
{
    char num[1005];

    while(1)
    {
        cin >> num;

        if(num[0] == '0')
            return 0;

        cout << digit_sum(num) << endl;;
    }
}
