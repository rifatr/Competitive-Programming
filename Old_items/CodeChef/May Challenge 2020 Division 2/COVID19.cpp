#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, c, inp, i, j;
    vector <int> x1, x2;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++) {
            cin >> inp;
            x1.push_back(inp);
        }

        for(i = 0; i < n; i++)
        {
            c = 0;
            //cout << "affected = " << x1[i] << endl;
            for(j = i + 1; j < n; j++) {
                inp = x1[j] - x1[j - 1];

                if(inp < 3) {
                    c++;
                    //cout << x1[j] << " is affected by " << x1[j - 1] << endl;
                }
                else
                    break;
            }
            for(j = i - 1; j >= 0; j--) {
                inp = x1[j + 1] - x1[j];

                if(inp < 3) {
                    c++;
                    //cout << x1[j] << " is affected by " << x1[j + 1] << endl;
                }
                else
                    break;
            }
            x2.push_back(c);
        }

        sort(x2.begin(), x2.end());

//        for(i = 0; i < x2.size(); i++)
//            cout << x2[i] << endl;

        c = x2.size();
        cout << x2[0] + 1 << " " << x2[c - 1] + 1 << endl;

        x1.clear();
        x2.clear();
    }

    return 0;
}
