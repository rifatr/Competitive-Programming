#include<bits/stdc++.h>

using namespace std;

const int N = 11;
int n;
int ara[N], lis[N];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i];

    for(int i = 0; i < n; i++)
    {
        int is = 0;

        for(int j = 0; j < i; j++)
            if(ara[i] > ara[j])
                is = max(is, lis[j]);

        lis[i] = is + 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans = max(ans, lis[i]);

    cout << ans << '\n';

    return 0;
}

