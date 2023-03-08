#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n, k, test, c, value, i, j;
    set <long long> x;

    scanf("%lld", &test);

    for(i = 1; i <= test; i++)
    {
        scanf("%lld", &n);

        for(j = 0; j < n; j++) {
            scanf("%lld", &value);
            x.insert(value);
        }

//        sort(value, value+n);
//
//        c = 0;
//        for(j = 1; j < n; j++) {
//            if(value[j] != value[j - 1])
//                c++;
//        }

        c = x.size();
        x.clear();

        printf("Case %lld: %lld\n", i, c);
    }

    return 0;
}

