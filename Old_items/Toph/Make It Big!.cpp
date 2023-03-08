#include<bits/stdc++.h>

using namespace std;
const int N = 2e9;
string cnv(long long n)
{
    string s;
    while(n)
    {
        s += '0' + (n % 10);
        n/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string f(string s, int swp)
{
    if(!swp)
        return s;

    string mx = "", flg;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            flg = s;

            swap(flg[i], flg[j]);

            flg = f(flg, swp - 1);

            mx = max(flg, mx);
        }
    }

    return mx;
}

int main()
{
    int t;

    cin >> t;

    for(int z = 0; z < t; z++)
    {
        string s;

        cin >> s;
//        long long v = rand() % N;
//        s = cnv(v);
//        cout << s << ' ';
//
//        int n = s.size(), sp = 2, swp[2] = {0};
//
//        for(int i = 0; i < n and sp; i++)
//        {
//            char x = s[i];
//            int y = i;
//            for(int j = i + 1; j < n; j++)
//            {
//                if(s[j] >= x)
//                    x = s[j], y = j;
//            }
//
//            if(y != i and s[i] < s[y])
//                swap(s[i], s[y]), swp[--sp] = y, cout << s << ' ';
//        }
//
//        cout << s <<  ' ' << sp << ' ';
//
//        if(!sp)
//        {
//            sort(swp, swp + 2);
//            if(s[swp[0]] < s[swp[1]])
//                swap(s[swp[0]], s[swp[1]]);
//        }
//
//        if(sp)
//            for(int i = 0; i < n and sp; i++)
//                for(int j = i + 1; j < n; j++)
//                    if(s[i] == s[j])
//                        sp = 0;
//
//        if(sp > 0)
//            swap(s[n - 1], s[n - 2]), sp--;
//        if(sp > 0)
//            swap(s[n - 1], s[n - 2]);

        cout << f(s, 2) << '\n';
    }

    return 0;
}
