#include<bits/stdc++.h>

using namespace std;

int note[5] = {1, 5, 10, 20, 100}, tk, tn;

void build(int i)
{
    if(i < 0 or tk <= 0)
        return;

    int x = tk / note[i];

    tn += x;
    tk -= x * note[i];

    build(i - 1);
}

int main()
{
    cin >> tk;

    build(4);

    cout << tn << '\n';

    return 0;
}
