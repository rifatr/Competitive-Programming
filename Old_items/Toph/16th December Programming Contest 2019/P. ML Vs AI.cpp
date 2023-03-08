#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, sum = 0, i, j, rate = 0, avg = 0, counter = 0, a, b;
    scanf("%lld", &n);
    vector <long long> m, s;

    for(i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        m.push_back(a);
        s.push_back(b);
        sum += m[i];
    }
     if(n == 0) {
        printf("0\n");
        return 0;
    }

    avg = sum / n;
    //cout << avg << endl;
    for(i = 0; i < n; i++){
        if(s[i] == 0)
            continue;
        rate = (m[i] * 10) / s[i];
        //cout << rate << endl;
        if(m[i] >= 150 && rate >= 7 && m[i] >= avg)
            counter++;
    }

    printf("%lld\n", counter);

    return 0;
}
