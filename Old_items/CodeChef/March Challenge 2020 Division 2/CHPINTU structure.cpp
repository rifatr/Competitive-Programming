#include<bits/stdc++.h>

using namespace std;

struct fruits
{
    int type;
    int price;
};

bool compare(fruits a, fruits b)
{
    return a.type < b.type;
}

int main()
{
    int t, n, m, i, j;

    set <int> total;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        fruits box[n];

        for(i = 0; i < n; i++)
            cin >> box[i].type;
        for(i = 0; i < n; i++)
            cin >> box[i].price;

        sort(box, box + n, compare);

        int sum = box[0].price;
        for(i = 0; i < n; i++)
        {
            if(box[i].type == box[i + 1].type)
                sum += box[i + 1].price;
            else
            {
                total.insert(sum);
                sum = box[i + 1].price;
            }
        }

        //auto it = total.begin();
        cout << *total.begin() << endl;

        total.clear();
    }

    return 0;
}
