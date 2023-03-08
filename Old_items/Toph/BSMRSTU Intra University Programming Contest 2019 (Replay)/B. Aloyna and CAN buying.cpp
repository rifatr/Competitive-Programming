#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, k, inp, x, counter1 = 1, counter2 = 0;
    vector <int> can;

    cin >> n >> k;


    for(i = 0; i < n; i++)
    {
        cin >> inp;
        can.push_back(inp);
    }

    sort(can.begin(), can.end());

    for(i = 0; i < n - 1; i++)
    {
        if(can[i] == can[i + 1]) {
            counter1++;
            if(i+1 == n - 1) {
                if(counter1 > counter2)
                {
                    counter2 = counter1;
                    x = can[i+1];
                }
            }
        }
        else
        {
            if(counter1 > counter2)
            {
                counter2 = counter1;
                x = can[i];
            }

            counter1 = 1;
        }
    }
    //    if(can[n - 1] == can[n - 2])
//    {
//        counter1++;
//        if(counter1 > counter2)
//        {
//            x = can[n - 1];
//        }
//    }

    cout << x << endl;
    return 0;
}
