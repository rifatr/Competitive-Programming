#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, l, c = 0;
    char p;
    map <char, int> cards;
    map <char, int> :: iterator it;

    cin >> n >> m;

    for(i = 0; i < 2 * m; i++)
    {
        cin >> p;
        cards[p]++;
    }

    for(it = cards.begin(); it != cards.end(); it++)
    {
        if(cards[it] == 1)
            c++;
        else if(cards[it] < cards.size() - 1)
            c++;
    }

   // cout << --a + b - x << endl;

    return 0;
}

