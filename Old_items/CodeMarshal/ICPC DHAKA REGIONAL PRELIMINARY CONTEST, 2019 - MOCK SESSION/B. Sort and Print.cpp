#include<bits/stdc++.h>

using namespace std;

struct data
{
    int roll;
    string name;
    int mark;
};

int main()
{
    int n, i, j;
    scanf("%d", &n);
    data st[n];

    for(i = 0; i < n; i++)
    {
        cin >> st[i].roll >> st[i].name >> st[i].mark;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(st[i].mark < st[j].mark)
            {
                swap(st[i].mark, st[j].mark);
                swap(st[i].name, st[j].name);
                swap(st[i].roll, st[j].roll);


            }
        }
    }

    printf("Roll | Name       | Marks\n");
    printf("-------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%d | %s       | %f\n", st[i].roll, st[i].name, st[i]. mark);;
    }

    return 0;
}
