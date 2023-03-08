#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    freopen("output.txt", "w", stdout);
    int x = 1, test = 9;

    //cin >> x >> test;
    vector <int> f, ff;

    for(int z = x; z <= test; z++)
    {
        cout << z << endl;
        ff.push_back(z);
        int k = 0;
        f = ff;

        do
        {
            bool p = 1;
            loop(i, 0, z - 1) if(!(f[i] & f[i + 1])) {p = 0;break;}

            if(p)
            {
                lop(z) cout << f[i] << ' ';
                cout << endl;
                k++;
            }
        }
        while(next_permutation(f.begin(), f.end())); 

        if(!k) cout << -1 << endl;

        cout << endl;      
    }

    return 0;
}
