#include<iostream>
#include<math.h>

using namespace std;

#define N 10010

bool num[N + 1];
int x;

void d(int n)
{
    x++;
    if(n >= N) return;

    int s = n;

    while(n)
    {
        s += (n % 10);
        n /= 10;
    }

    num[s] = true;

    d(s);
}

int main()
{
    for(int i = 1; i < 10000; i++) d(i);
    //cout << x << '\n';

    for(int i = 1; i < 10000; i++) if(!num[i]) cout << i << '\n';

    return 0;
}
