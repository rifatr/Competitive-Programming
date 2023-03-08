#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, n, m, index;

    scanf("%d", &n);

    int ent[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &ent[i]);
    }

    i = 0;
    while(1)
    {
        m = ent[i];
        //cout << m << endl;
        if(m == 0) {
            index = i + 1;
            break;
        }

        for(j = 0; j < n; j++) {
            ent[j]--;
            if(ent[j] < 0)
                ent[j] = 0;
            //printf("%d ", ent[j]);
        }

        i++;
        if(i == n)
            i = 0;
    }

    printf("%d\n", index);

    return 0;
}
