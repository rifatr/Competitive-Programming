#include<bits/stdc++.h>
#include<map>

#define ll long long

using namespace std;

int main()
{
    map <string, ll> dic;
    map <string, ll> ::iterator it;
    string word;
    ll n, q, x, i;

    scanf("%lld", &q);

    for(i = 0; i < q; i++)
    {
        scanf("%lld", &n);
        if(n == 0)
        {
            cin >> word >> x;
            dic[word] = x;
        }
        else if(n == 1)
        {
            cin >> word;
            it = dic.find(word);
            if(it != dic.end())
                printf("%lld\n", it -> second);
            else
                printf("0\n");
        }
        else
        {
            cin >> word;
            dic.erase(word);
        }
    }

    return 0;

}
