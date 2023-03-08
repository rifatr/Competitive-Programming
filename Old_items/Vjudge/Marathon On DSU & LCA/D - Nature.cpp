#include<bits/stdc++.h>

#define ll long long

using namespace std;

map <string, string> bird;
vector <string> rep;

void OJ()
{
    freopen("D input.txt", "r", stdin);
    freopen("D output.txt", "w", stdout);
}

string findrep(string a)
{
    if(bird[a] == a)
        return a;

    return bird[a] = findrep(bird[a]);
}

void Union(string a, string b)
{
    string m = findrep(a), n = findrep(b);

    bird[m] = n;
}

int main()
{
    //OJ();

    ll c, r, i, j;
    string s, t;

    while(1)
    {
        bird.clear();

        scanf("%lld %lld", &c, &r);
        if(c == 0 && r == 0)
            break;

        for(i = 0; i < c; i++)
        {
            cin >> s;
            bird[s] = s;
        }

        for(i = 0; ; i++)
        {
            if(i == r) {
                cin.ignore();
                cin.ignore();
                break;
            }
            cin >> s >> t;
            Union(s, t);
        }

        ll x = 0, maxx = 0;

//        for(auto it = bird.begin(); it != bird.end(); it++)
//            cout << it -> first << "'s rep = " << it -> second << "\n";

        for(auto it = bird.begin(); it != bird.end(); it++)
            string m = findrep(it -> first);

        for(auto it = bird.begin(); it != bird.end(); it++)
            rep.push_back(it -> second);

        sort(rep.begin(), rep.end());

        for(i = 0; i < rep.size() - 1; i++)
        {
            //cout << rep[i] <<  endl;
            if(rep[i] != rep[i + 1]) {
                maxx = max(maxx, x);
                x = 0;
            }
            else
                x++;
        }

        maxx = max(maxx, x);

        printf("%lld\n", maxx + 1);
        rep.clear();
    }

    return 0;
}
