#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, k, i, j, g, l, x, sum, inp, bi, ag, counter;
    vector <int> a, b;

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i = 0; i < n; i++)
        {
            cin >> inp;
            a.push_back(inp);
            //cout << n << endl;
        }
        for(i = 0; i < m; i++)
        {
            cin >> inp;
            b.push_back(inp);
            //cout << m << endl;
        }
        sort(a.begin(), a.end());
        for(i = 0; i < m; i++)
        {
            for(g = n - 1; g >= 0; g--)
            {
                if(a.at(g) < b.at(i))
                {
                    ag = a.at(g);
                    bi = b.at(i);
                    sum = ag + bi;
                    break;
                }
                else
                {
                    ag = 0;
                    bi = b.at(i);
                    sum = ag + bi;
                }
            }
            for(l = 0; l < k; l++)
            {
                a.push_back(sum);
            }
        }
        counter = 0;
        for(i = 0; i < a.size(); i++)
        {
            for(j = 0; j < b.size(); j++)
            {
                /*if(b.at(j) <= a.at(i))
                {
                    counter++;
                    cout << a.at(i) << " " << b.at(j) << endl;
                }*/
                sum = 0;
                //if(j > 0) {
                for(l = 0; l <= j; l++) {
                    if(b.at(l) <= a.at(i))
                        sum = sum + b.at(l);
                }
                if(sum > 0 && sum <= a.at(i))
                {
                    counter = counter + 1;
                    //cout << a.at(i) << " sum =" << sum << endl;
                }
               //}

            }
        }
        printf("%d\n", counter);
    }
    return 0;
}
