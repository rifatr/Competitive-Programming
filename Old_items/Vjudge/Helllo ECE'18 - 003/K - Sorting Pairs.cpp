#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Point
{
    ll x, y;

    bool operator < (const Point & B) const {
        if(x == B.x)
            return y < B.y;
        else
            return x < B.x;
    }
};

//bool compare(Point A, Point B)
//{
//    if(A.x == B.x)
//        return A.y < B.y;
//    else
//        return A.x < B.y;
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, a, b;

    cin >> n;
    Point point[n];
    for(ll i = 0; i < n; i++)
        cin >> point[i].x >> point[i].y;

    sort(point, point + n);

    for(ll i = 0; i < n; i++)
        cout << point[i].x << " " << point[i].y << endl;

    return 0;
}
