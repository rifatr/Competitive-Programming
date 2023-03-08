#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, l, j, k, x, z;
    vector <string> vs;
    string s, s2 = "", fs;

    cin >> t;
    cin.ignore();

    for(k = 1; k <= t; k++)
    {
        cin >> s;
        l = s.size();

        for(i = 0; i < l;)
        {
            for(j = i; j < l; j++)
            {
                if(s[i] == s[j])
                    s2 += s[j];
                else
                    break;
            }
            i += (j - i);

            //cout << "s2 = " << s2 << endl;

            x = s2[0] - '0';

            for(z = 0; z < x; z++)
                vs.push_back("(");
            vs.push_back(s2);
            for(z = 0; z < x; z++)
                vs.push_back(")");

            s2.clear();
            s2 = "";
        }

        printf("Case #%d: ", k);
        for(i = 0; i < vs.size(); i++)
            cout << vs[i];
        cout << endl;

        vs.clear();
    }

    return 0;
}
