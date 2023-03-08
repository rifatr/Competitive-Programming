#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, q, n, i, index, mid, lo, hi;

    cin >> t >> q;

    int nun[t];

    for(i = 0; i < t; i++)
        cin >> nun[i];

    set <int> mum(nun, nun + t);
    set <int> :: iterator it;
    vector <int> num;

    for(it = mum.begin(); it != mum.end(); it++)
        num.push_back(*it);

    //cout << num[1];

    while(q--)
    {
        cin >> n;

        lo = 0;
        hi = num.size() - 1;

        while(1)
        {
            mid = lo + (hi - lo) / 2;

            if(num[mid] == n)
                break;
            else if(num[mid] < n)
                lo = mid + 1;
            else if(num[mid] > n)
                hi = mid - 1;
            if(lo > hi)
                break;
        }

        if(num[mid] == n) {
//            for(i = mid - 1; i >= 0; i--) {
//                if(n == num[i])
//                    mid = i;
//                else
//                    break;
//            }
            cout << mid << endl;
            //cout << lower_bound(num, num + t, n) - num << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}

