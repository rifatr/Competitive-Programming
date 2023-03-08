#include<bits/stdc++.h>

using namespace std;

unsigned long long stsum(char x[])
{
    unsigned long long sum = 0;
    for(int i = 0; i < strlen(x); i++)
        sum += x[i] - '0';

    return sum;
}

int main()
{
    unsigned long long t, i, j, k, a, b, sum, counter;

    char num[100];

    cin >> t;

    for(i = 1; i <= t; i++)
    {
        cin >> a >> b;

        for(int x = 0; x < a - 1; x++) {
            num[x] = x + 1;
            //cout << num << endl;
        }

        counter = 0;
        for(int x = a; x <= b; x++) {
            num[x - 1] = x;
            //cout << num << endl;
            if(stsum(num) % 3 == 0) {
                counter++;
                cout << stsum(num) << endl;
            }

        }

        cout << "Case " << i << ": " << counter << "\n";
    }

    return 0;
}
