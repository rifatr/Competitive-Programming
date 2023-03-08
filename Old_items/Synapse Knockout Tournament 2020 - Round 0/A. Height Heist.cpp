#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, inp, sum, count;
    double avg;
    vector <int> height;

    cin >> t;

    while(t--)
    {
        cin >> n;
        sum = 0;
        for(i = 0; i < n; i++)
        {
            cin >> inp;
            height.push_back(inp);
            sum += inp;
        }

        avg = floor(sum / (n * 1.0));
        //cout << "Sum = " << sum << "\tavg = " << avg << endl;

        count = 0;
        for(i = 0; i < n; i++)
        {
            if(avg <= height[i]) {
                count++;
                //cout << height[i] << endl;
            }
        }

        cout << count << endl;
    }

    return 0;
}
