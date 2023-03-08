#include<bits/stdc++.h>

using namespace std;

char ar[27];
set <char> uniq, two;

void OJ()
{
    freopen("C input.txt", "r", stdin);
    //freopen("C output.txt", "w", stdout);
}

char findrep(char a)
{
    if(ar[a - 65] == a)
        return a;

    return ar[a - 65] = findrep(ar[a - 65]);
}

void Union(string s)
{
    char a = findrep(s[0]), b = findrep(s[1]);

    ar[a - 65] = b;
    //printf("%c 's rep = %c\n", a, b);
}

int main()
{
    //OJ();

    int t, x, i, j;
    char a, b, s;
    string edge;

    scanf("%d", &t);
    cin.ignore();
    cin.ignore();


    for(j = 0; j < t; j++)
    {
        scanf("%c", &s);
        cin.ignore();

        int saiz = s - 64;
        for(i = 0; i < 27; i++) {
            ar[i] = i + 65;
        }

        while(1)
        {
            getline(cin, edge);

            if(edge.size() == 0)
                break;

            Union(edge);
        }

        x = 0;

        for(i = 0; i < saiz; i++)
        {
            if(i == ar[i] - 65)
                x++;
            //printf("%c 's rep = %c\n", i + 65, ar[i]);
        }

        printf("%d\n", x);
        if(j != t - 1)
            printf("\n");
    }

    return 0;
}
