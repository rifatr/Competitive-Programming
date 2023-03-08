#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define bug cout << "bug\n"

int cnt[26], sum;
vector <int> v;

int main()
{
    string s;
    int mv = 99999999;

    cin >> s;

    int n = s.size();

    lop(0, n)
        cnt[s[i] - 'a']++;

    lop(0, 26)
        if(cnt[i])
            v.push_back(cnt[i]);

    int p = v.size();
    int saiz = p;

    while(p > 0)
    {
//        if(26 % p) {
//            p--;
//            continue;
//        }

        int req = n / p, i = 0;

        int mv2 = 0, f = 0;

        while(i < saiz)
        {
//            if(p == 1 and i == 0) {
//                i++; continue;}

            int z = v[i] - req;

            if(z >= 0)
            {
                mv2 += z;
                f += z;
            }

            else
            {
                if(v[i] + f >= req)
                    f += z;

                else
                {
                    mv2 += v[i];
                    f += v[i];
                }
            }

            i++;
        }

        mv2 += n % p;
        mv = min(mv, mv2);
        p--;
    }

    cout << mv << '\n';

    return 0;
}
