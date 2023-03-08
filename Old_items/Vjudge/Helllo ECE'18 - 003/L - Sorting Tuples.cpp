#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Item
{
    ll value, weight, data;
    char type;
    string name;
};

bool compare(Item A, Item B)
{
    if(A.value == B.value)
    {
        if(A.weight == B.weight)
        {
            if(A.type == B.type)
            {
                if(A.data == B.data)
                    return A.name < B.name;
                else
                    return A.data < B.data;
            }
            else
                return A.type < B.type;
        }
        else
            return A.weight < B.weight;
    }
    else
        return A.value < B.value;
}

int main()
{
    ll n, i;

    cin >> n;
    Item items[n];

    for(ll i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight >> items[i].type >> items[i].data >> items[i].name;

    sort(items, items + n, compare);

    for(ll i = 0; i < n; i++)
        cout << items[i].value << " " << items[i].weight << " " << items[i].type << " " << items[i].data << " " << items[i].name << endl;

    return 0;
}
