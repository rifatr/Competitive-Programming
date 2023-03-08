#include <bits/stdc++.h>

using namespace std;

int main()
{
    int br, bl, gr, gl;
    int l1, l2, r1, r2;
    int l12, l13, l22, r12, r13, r22;

    cin >> gl >> gr >> bl >> br;

    l1 = ceil(gl / (br * 1.0));
    l12 = ceil(gl / (br / 2.0));
    l13 = ceil(gl / (br / 3.0));

    l2 = ceil(br / (gl * 1.0));
    l22 = ceil(br / (gl / 2.0));

    r1 = ceil(gr / (bl * 1.0));
    r12 = ceil(gr / (bl / 2.0));
    r13 = ceil(gr / (bl / 3.0));

    r2 = ceil(bl / (gr * 1.0));
    r22 = ceil(bl / (gr / 2.0));

    //cout << l1 << endl << l2 << endl << l1 << endl << l2 << endl;
    if(((l1 <= 2 || l12 <= 2 || l13 <= 2) && (l2 <= 3 || l22 <= 3)) || ((r1 <= 2 || r12 <= 2 || r13 <= 2) && (r2 <= 3 || r22 <= 3)))
       printf("YES\n");
    else
        printf("NO\n");

    //return 0;
main();
}


