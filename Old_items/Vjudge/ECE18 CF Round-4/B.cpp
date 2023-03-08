#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    int n, s = 0;

    cin >> n;

    int tree[n + 1], color[n + 1] = {0}, clr[n + 1] = {0};

    tree[1] = 0;
    color[0] = -1;
    clr[0] = -1;
    lop(2, n + 1) cin >> tree[i];
    lop(1, n + 1) cin >> color[i];

    for(int i = n; i > 0; i--)
    {
        int l = color[i];
        if(!clr[i])
        {
            cout << i << '\n';
            for(int j = i; j >= 1;)
            {
                clr[j] = color[j];
                j = tree[j];
                if(j == 0) break;

                if(l != color[j])
                {
                    s++;
                    l = color[j];
                }
                printf("%d %d %d\n", j, clr[j], s);
            }
        }
    }

    cout << s + 1 << '\n';

    return 0;
}
