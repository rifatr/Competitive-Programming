#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, c = 0;
    char food[1001];

    scanf(" %[^\n]s", food);

    for(i = 0; food[i] != '\0'; i++) {
        if(food[i] == ' ' && food[i + 1] != ' ')
            c++;
    }

    cout << c + 1 << endl;

    return 0;
}
