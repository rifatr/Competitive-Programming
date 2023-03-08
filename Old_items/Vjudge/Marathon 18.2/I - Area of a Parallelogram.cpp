#include<bits//stdc++.h>

using namespace std;

int main()
{
    int t;
    int ax, ay, bx, by, cx, cy, dx, dy, area, apx;

    cin >> t;

    for(int i = 1; i <= t; i++) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        dx = ax + (cx - bx);
        dy = ay + (cy - by);

        int ab = ceil(sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by))));
        int cd = ceil(sqrt(((cx - dx) * (cx - dx)) + ((cy - dy) * (cy - dy))));

        int height = abs(dy - ay);

        area = ceil(.5 * (ab + cd) * height);

        cout << "Case " << i << ": " << dx << " " << dy << " " << area << "\n";
    }

    return 0;
}
