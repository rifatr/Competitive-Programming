#include<bits/stdc++.h>

using namespace std;

int main()
{
    char line[1202];
    int i;

    scanf(" %[^\n]s", line);

    for(i = 0; line[i] != '\0'; i++) {
        if(line[i] >= 'A' && line[i] <= 'Z')
            line[i] += 32;
        else if(line[i] >= 'a' && line[i] <= 'z')
            line[i] -= 32;
    }
    printf("%s\n", line);

    return 0;
}
