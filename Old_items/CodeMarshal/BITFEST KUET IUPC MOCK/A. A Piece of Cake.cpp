#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, p, i = 0, j;

    cin >> n;

    while(i < n) {
        cin >> p;
        j = 0;
        while(j <= p) {
            cout << j;
            if(j < p)
                cout << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
