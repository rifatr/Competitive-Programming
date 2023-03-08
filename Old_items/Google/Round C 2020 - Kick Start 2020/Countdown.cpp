#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt, n, k, t = 1;
    vector <int> ar;

    cin >> tt;

    while(tt--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            int p; cin >> p;
            ar.push_back(p);
        }

        int c = 0;

        for(int i = 0; i < n; i++)
        {
            if(ar[i] == k)
            {
                int p = k, f = 1;
                for(int j = i; j <n; j++)
                {
                    if(ar[j] == p)
                        p--;
                    else
                    {
                        f = 0;
                        break;
                    }
                    if(p == 0) break;
                    i++;
                }

                if(f == 1) c++;
            }
        }

        printf("Case #%d: ", t++);

        cout << c << '\n';
        ar.clear();
    }



    return 0;
}

