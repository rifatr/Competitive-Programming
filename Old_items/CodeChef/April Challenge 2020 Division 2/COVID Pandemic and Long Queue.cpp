#include<bits/stdc++.h>

using namespace std;

int main()
{
    //queue <bool> line;
    int n, t, first, people;
    bool person, result;

    cin >> t;

    while(t--)
    {
        cin >> n;

        first = -1;
        result = true;
        people = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> person;

            if(person == 1 && first == -1)
                first = i;

            if(person == 1)
                people++;

            if(person == 1 && people > 1 && result == true)
            {
                if(i - first < 6) {
                    result = false;
                    //cout << i - first << " " << i << " " << first << endl;
                }

                first = i;
            }
        }

        if(result == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
