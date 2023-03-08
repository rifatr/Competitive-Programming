#include<bits/stdc++.h>
#include<vector>

using namespace std;

//float stdev(float *arra, int siz)
//{
//    float sum = 0.0, mean = 0.0, stdv;
//    int i;
//    for(i = 0; i < siz; i++) {
//        sum += arra[i];
//    }
//    mean = sum / siz;
//    for(i = 0; i < siz; i++) {
//        stdv += (arra[i] - mean) * (arra[i] - mean);
//    }
//    return sqrt(stdv / siz);
//}

int main()
{
    int i, n;

    //vector <int> s[n];

    while(1)
    {
        float sum = 0.0, mean, deviation, temp = 0.0;

        cin >> n;
        if(n == 0)
            break;
        float s[n];

        for(i = 0; i < n; i++)
            cin >> s[i];

        for(i = 0; i < n; i++) {
            sum += s[i];
            //cout << sum << " ";
        }

        //deviation = stdev(s, n);
       // cout << endl;
        mean = sum / n;

        for(i = 0; i < n; i++)
        {
//            sum += s[i];
//            mean = sum / (i + 1);
            temp += (s[i] - mean) * (s[i] - mean);

           // printf("temp = %lf\n", temp);
        }
        deviation = sqrt(temp / n);
        printf("%.8f\n", deviation);
        //cout << stdev(s, n) << endl;
    }
}
