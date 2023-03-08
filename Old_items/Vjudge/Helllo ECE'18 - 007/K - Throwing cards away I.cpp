#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;

    while(cin >> x and x)
    {
        queue <int> cards;

        lop(1, x + 1) cards.push(i);

        cout << "Discarded cards:";
        lop(1, x) {
            printf(" %d", cards.front());
            if(i < x - 1) printf(",");
            cards.pop();

            cards.push(cards.front());
            cards.pop();
        }
        cout << '\n';

        cout << "Remaining card: " << cards.front() << '\n';
    }

    return 0;
}

