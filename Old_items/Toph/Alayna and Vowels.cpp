#include<bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int counter = 0;

    cin >> line;

    for(int i = 0; i < line.size(); i++) {
        if(line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U' ||
           line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
            counter++;
    }

    cout << counter << endl;

    return 0;
}
