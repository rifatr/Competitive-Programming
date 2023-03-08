#include <bits/stdc++.h>

using namespace std;

int main()
{
    int br, bl, gr, gl;
    double l1, l2, r1, r2;

    cin >> gl >> gr >> bl >> br;

    if(bl == 0 && br == 0) {
        printf("NO\n");
        return 0;
    }

    if(br != 0) {
    l1 = ceil(gl / (br * 1.0)); }
    l2 = ceil(br / (gl * 1.0));

    if(bl != 0) {
    r1 = ceil(gr / (bl * 1.0)); }
    r2 = ceil(bl / (gr * 1.0));

    //cout << l1 << endl << l2 << endl << l1 << endl << l2 << endl;
    if((l1 <= 3 && l2 <= 5 && l2 > 0) || (r1 <= 3 && r2 <= 5 && r2 > 0))
       printf("YES\n");
    else
        printf("NO\n");

    return 0;
//main();
}
