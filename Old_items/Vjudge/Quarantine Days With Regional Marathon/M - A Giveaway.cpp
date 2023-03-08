#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x;

    int list[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809,
                7529536, 11390625, 16777216, 24137569, 34012224,47045881, 64000000, 85766121};

    while(1)
    {
        cin >> x;
        if(x == 0)
            break;

        string res = "Ordinary\n";

        for(int i = 0; i < 21; i++)
        {
            if(x == list[i])
                res = "Special\n";
        }

        cout << res;
    }

    return 0;
}
