#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, s, e, n, i, j, k, f, c, z;
    vector <string> schedule;
    int cam[1441], jam[1441];
    int *stc, *enc, *stj, *enj;
    //cout << cam[0] << jam[0];

    cin >> t;

    for(k = 1; k <= t; k++)
    {
        cin >> n;

        for(i = 0; i <= 1440; i++) {
            cam[i] = 0;
            jam[i] = 0;
        }

        f = 0;
        for(i = 0; i < n; i++)
        {
            cin >> s >> e;

            if(f == 0)
            {
                c = z = 0;
                for(j = s; j < e; j++) {
                    if(cam[j] == 1)
                        c++;
                    if(jam[j] == 1)
                        z++;
                }

                if(c == 0) {
                    for(j = s; j < e; j++)
                        cam[j] = 1;
                    schedule.push_back("C");
                    //printf("%d %d %d C\n", s, e, c);
                }
                else if(z == 0) {
                    for(j = s; j < e; j++)
                        jam[j] = 1;
                    schedule.push_back("J");
//                    printf("%d %d %d J\n", s, e, z);
//                    printf("%d %d C = %d\n", s, e, c);
                }
                else {
                    f = 1;
                    //printf("%d %d C %d J %d\n", s, e, c, z);
                }
            }
        }

        printf("Case #%d: ", k);
        if(f == 1)
            cout << "IMPOSSIBLE\n";
        else {
            for(i = 0; i < schedule.size(); i++)
                cout << schedule[i];
            cout << endl;
        }

        schedule.clear();
    }

    return 0;
}

/*
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
*/
