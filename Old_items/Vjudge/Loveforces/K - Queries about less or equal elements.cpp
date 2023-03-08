#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, inp, count, i, j;
    vector <long long> a;

    scanf("%lld %lld", &n, &m);

    for(i = 0; i < n; i++)
    {
        scanf("%lld", &inp);
        a.push_back(inp);
    }

    sort(a.begin(), a.end());

    for(i = 0; i < m; i++)
    {
        scanf("%lld", &inp);
        //b.push_back(inp);

        count = 0;
        for(j = 0; j < n; j++){
            if(a[j] <= inp) {
                count++;
                //cout << b[i] << "'s less is " << a[j] << endl;
            }
            else
                break;
        }
        printf("%lld", count);
        if(i - 1 < m)
            printf(" ");
    }



//    for(i = 0; i < m; i++)
//    {
//        count = 0;
//        for(j = 0; j < n; j++){
//            if(a[j] <= b[i]) {
//                count++;
//                //cout << b[i] << "'s less is " << a[j] << endl;
//            }
//            else
//                break;
//        }
//        printf("%lld", count);
//        if(i - 1 < m)
//            printf(" ");
//    }

    printf("\n");

    return 0;
}
