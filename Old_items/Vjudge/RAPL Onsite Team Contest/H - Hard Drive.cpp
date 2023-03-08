#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, c, b, i, j;
    cin >> n >> c >> b;
    char bit[n];
    int broked[b];

    for(i = 0; i < b; i++)
        cin >> broked[i];

    bit[0] = '1';
    for(i = 1; i < n; i++)
        bit[i] = '1';
//    for(i = 0; i < n; i++)
//        cout << bit[i] << endl;;
    for(i = 0; i < b; i++)
        bit[broked[i] - 1] = '0';

    if(bit[1] == '0')
        bit[0] = '0';

    for(i = 0, j = 1; j < c; i++) {
        if(bit[i] == '0')
            continue;
        else if(bit[i - 1] == '0' || bit[i + 1] == '0'){
            bit[i] = '1';
            j++;
            //cout << i << "=" << bit[i] << " " << j << endl;
            //j++;
        }
        else {
            bit[i] = '0';
            j++;
            //cout << i << "=" << bit[i] << " " << j << endl;

        }
    }

    for(i = 0; i < n; i++)
        cout << bit[i];
    cout << endl;

    return 0;
}
