#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, power[18], flag = 0;
    for(i = 0; i < 18; i++)
        scanf("%d", &power[i]);
    for(i = 0; i < 17; i += 2)
    {
        if(power[i] == power[i + 1])
        {
            printf("Thanos Destroyed half of us\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        if(power[0] > power[1])
            printf("Iron Man\n");
        else
            printf("Captain America\n");
        if(power[2] > power[3])
            printf("Thor\n");
        else
            printf("Black Widow\n");
        if(power[4] > power[5])
            printf("The Hulk\n");
        else
            printf("Black Panther\n");
        if(power[6] > power[7])
            printf("Shuri\n");
        else
            printf("Okoye\n");
        if(power[8] > power[9])
            printf("Ant Man\n");
        else
            printf("Wasp\n");
        if(power[10] > power[11])
            printf("Doctor Strange\n");
        else
            printf("Winter Solder(Bucky Barners)\n");
        if(power[12] > power[13])
            printf("Hawkeye\n");
        else
            printf("Falcon\n");
        if(power[14] > power[15])
            printf("Maria Hill\n");
        else
            printf("Vison\n");
        if(power[16] > power[17])
            printf("War Machine\n");
        else
            printf("Hulkbuster\n");
    }

    return 0;
}






/*Iron Man
Captain America
Thor
Black Widow
The Hulk
Black Panther
Shuri
Okoye
Ant Man
Wasp
Doctor Strange
Winter Solder(Bucky Barners)
Hawkeye
Falcon
Maria Hill
Vison
War Machine
Hulkbuster
*/
