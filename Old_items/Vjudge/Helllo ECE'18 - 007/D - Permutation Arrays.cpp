#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define pb push_back

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    freopen("D input.txt", "r", stdin);

    int test, caseno = 1;

    cin >> test;
    cin.ignore();

    while(caseno <= test)
    {
        cin.ignore();

        int n = 1;
        double x;
        vector <double> aray;
        aray.pb(0);

        while(scanf("%lf", &x) == 1) {
            aray.pb(x);
            n++;
        }

        n /= 2;
        //cout << n << '\n';

        int index_array[n + 1];
        double given_array[n+ 1], permutate_array[n + 1];

        lop(1, aray.size()) {
            if(i <= n)
                index_array[i] = aray[i];
            else
                given_array[i - n] = aray[i];
        }

        lop(1, n + 1)
            permutate_array[index_array[i]] = given_array[i];

        lop(1, n + 1)
            printf("%lf\n", permutate_array[i]);


        if(caseno < test)
            cout << '\n';

        caseno++;

        //cout << "case = " << caseno << endl;
    }

    return 0;
}

