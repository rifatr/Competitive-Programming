#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, over, ball, i, l;

    string dit;

    cin >> t;
    cin.ignore();

    while(t--)
    {
        cin >> dit;

        l = dit.size();

        over = ball = 0;

        for(i = 0; i < l; i++)
        {
            if(dit[i] >= '0' && dit[i] <= '6')
                ball++;
            if(dit[i] == 'O')
                ball++;
        }

        //cout << ball << endl;

        over = ball / 6;
        ball = ball % 6;

        if(over != 0)
        {
            cout << over << " OVER";

            if(over > 1)
                cout << "S";
            if(ball != 0)
                cout << " ";
        }

        if(ball != 0)
        {
            cout << ball << " BALL";

            if(ball > 1)
                cout << "S";
        }

        cout << endl;


    }

    return 0;

}
