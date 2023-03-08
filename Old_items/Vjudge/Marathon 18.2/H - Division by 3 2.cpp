#include<bits/stdc++.h>

using namespace std;

int stsum(char x[])
{
    int sum = 0;
    for(int i = 0; x[i] != '\0'; i++)
        sum += (x[i] - '0');

    return sum;
}

int main()
{
    unsigned long long t, i, j, k, a, b, counter;

    char num[100];
//cout << stsum('9');
    cin >> t;

    for(i = 1; i <= t; i++)
    {
        cin >> a >> b;

        for(int x = 0; x < a - 1; x++) {
            num[x] = x + 1 + '0';
            cout << num[x] << endl;
        }

        counter = 0;
        for(int x = a; x <= b; x++) {
            num[x - 1] = x + '0';
            cout << num[x-1] << endl;
            if(stsum(num) % 3 == 0) {
                counter++;
                cout << "sum = " << stsum(num) << endl;
            }

        }

        cout << "Case " << i << ": " << counter << "\n";
    }

    return 0;
}

