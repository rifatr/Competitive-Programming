#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2, test, l;
    bool result;
    char order[105];

    scanf("%d", &test);

    for(int i = 1; i <= test; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf(" %s", &order);

        printf("Case %d: ", i);

        result = true;
        l = strlen(order) - 1;
        for(int j = 0; ;)
        {
            if(order[j] == 'L') {
                if(x1 > 0)
                    x1--;
                j++;
            }
            else if(order[j] == 'R') {
                if(x1 < 7)
                    x1++;
                j++;
            }
            else if(order[j] == 'U') {
                if(y1 < 7)
                    y1++;
                j++;
            }
            else if(order[j] == 'D') {
                if(y1 > 0)
                    y1--;
                j++;
            }

            if(x1 == x2 && y1 == y2) {
                result = false;
                break;
            }

            if(j == l)
                break;

            if(order[j] == 'L') {
                if(x2 > 0)
                    x2--;
                j++;
            }
            else if(order[j] == 'R') {
                if(x2 < 7)
                    x2++;
                j++;
            }
            else if(order[j] == 'U') {
                if(y2 < 7)
                    y2++;
                j++;
            }
            else if(order[j] == 'D') {
                if(y2 > 0)
                    y2--;
                j++;
            }

            if(x1 == x2 && y1 == y2) {
                result = false;
                break;
            }

            if(j == l)
                break;

        }

        if(!result)
            printf("COLLISION\n");
        else
            printf("SAFE\n");
    }

    return 0;
}

