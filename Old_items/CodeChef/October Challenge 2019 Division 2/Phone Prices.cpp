#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j, k, counter, inp;
    vector <int> price;

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> inp;
            price.push_back(inp);
            //cout << price[i] << endl;
        }

        counter = 1;

        for(i = 1; i < n;) {
            if(i == 1) {
                for(j = 1; j <= 5; j++) {
                    if(price[j] < price[0]) {
                        counter++;
                        cout << price[j] << endl;
                    }
                }
                cout << endl;
            }
            else {
                for(j = i; j < i + 5; j++) {
                    if(j == n)
                        break;
                    for(k = i - 5; k < i; k++) {
                        if(price[k] > price[j]) {
                            counter++;
                            cout << price[j] << endl;
                            cout << price[k] << endl;
                            break;
                        }

//                        if(j - 1 == n || j == n)
//                            break;
                    }
//                    if(j - 1 == n )
//                        break;
                }
            }

            i += 5;
        }

        cout << counter << endl;
    }

    return 0;
}
