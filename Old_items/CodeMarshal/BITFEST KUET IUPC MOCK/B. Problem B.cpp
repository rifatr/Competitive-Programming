#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, t, n, in;
    vector <int> v;

    scanf("%lld", &t);
    for(i = 0; i < t; i++) {
        scanf("%lld", &n);
        for(j = 0; j < n; j++) {
            scanf("%lld", &in);
            v.push_back(in);
        }
        sort(v.begin(), v.end());
        for(j = 0; j < n; j++) {
            cout << v[j] << " ";
        }
        int counter = 0;
        cout << counter << endl;
        for(j = 0; j < n - 1; j++) {
            if(v[j] < v[j + 1])
                continue;
            else
                counter++;
        }
        printf("Case %lld: %lld\n", i + 1, counter + 1);
        v.clear();
    }
    return 0;
}
