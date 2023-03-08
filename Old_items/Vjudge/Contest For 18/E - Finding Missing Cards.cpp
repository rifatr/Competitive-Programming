#include<bits/stdc++.h>

using namespace std;

#define mem(a) memset(a, 0, sizeof(a))

void print(bool a[], char c)
{
    for(int i = 1; i < 14; i++)
        if(!a[i])
            printf("%c %d\n", c, i);
}

int main()
{
    int n, num;
    char ch;
    bool S[14], H[14], C[14], D[14];

    mem(S); mem(H); mem(C); mem(D);

    cin >> n;

    for(int i = 0; i < n; i++)
    {

        cin >> ch >> num;
        if(ch == 'S')
            S[num] = 1;;
        if(ch == 'H')
            H[num] = 1;
        if(ch == 'C')
            C[num] = 1;
        if(ch == 'D')
            D[num] = 1;
    }

    print(S, 'S');
    print(H, 'H');
    print(C, 'C');
    print(D, 'D');

    return 0;
}
