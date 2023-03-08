#include<bits/stdc++.h>
#include<vector>
using namespace std;


int main()
{
    int x,y,z, i, j, k;
    scanf("%d %d %d",&x, &y, &z);
    //int a[x], b[y], c[z];
    vector <int> a, b, c;
    for(i = 0; i < x; i++)
    {
        cin >> input;
        a.push_back(input);
    }
    for(i = 0; i < y; i++)
    {
        cin >> input;
        b.push_back(input);
    }
    for(i = 0; i < z; i++)
    {
        cin >> input;
        c.push_back(input);
    }
    int p = a[x / 2];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for(i = 0; a[i] < p; i++)
    {
        printf("%d", a[i]);
    }


    /*for(i = 0; i < x; i++)
    {
        int v = a[i], cb = 0, cc = 0;
        for(j = 0; j < y; j++)
        {
            if(b[j] < v)
                cb++;
        }
        for(k = 0; k < z; k++)
        {
            if(c[k] > v)
                cc++;
        }
        p[i] = 1+cb+cc;
    }*/
    int max = p[0];
    for(i = 0; i < x; i++) {
        if(p[i] > max)
                max = p[i];
    }

    printf("%d", max);

    return 0;

}

