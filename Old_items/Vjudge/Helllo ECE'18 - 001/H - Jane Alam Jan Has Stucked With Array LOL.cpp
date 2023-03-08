#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, q, i, inp, d, k, j = 0;
    char c;
    vector <long long> arr;

    cin >> t;

    while(t--)
    {
        j++;
        cin >> n >> q;

        for(i = 0; i < n; i++) {
            cin >> inp;
            arr.push_back(inp);
        }

        while(q--)
        {
            cin >> c;
            cin.ignore();

            if(c == 'S') {
                cin >> d;
                for(i = 0; i < n; i++)
                    arr[i] += d;
            }

            else if(c == 'M') {
                cin >> d;
                for(i = 0; i < n; i++)
                    arr[i] *= d;
            }

            else if(c == 'D') {
                cin >> d;
                for(i = 0; i < n; i++)
                    arr[i] /= d;
            }

            else if(c == 'R')
                reverse(arr.begin(), arr.end());

            else {
                cin >> d >> k;
                swap(arr[d], arr[k]);
            }
        }

        printf("Case %lld:\n", j);
        for(i = 0; i < n; i++) {
            cout << arr[i];
            if(i < n - 1)
                cout << " ";
        }

        cout << endl;
        arr.clear();
    }

    return 0;
}
