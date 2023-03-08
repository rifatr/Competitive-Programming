#include<math.h>
#include<iostream>

using namespace std;

int main()
{
    double n, sum;

    while(cin >> n and n > 0.00)
    {
        sum = 0.00;
        int x = 0;

        for(int i = 2; sum < n; i++)
        {
            sum += (double) (1.0 / i);
            //cout << sum << '\t';
            x++;
        }

        cout << x << " card(s)\n";
    }

    return 0;
}
