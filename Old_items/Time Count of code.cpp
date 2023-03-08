#include<bits/stdc++.h>

using namespace std;
using namespace chrono;


int main()
{
#ifdef LOCAL
    auto start = high_resolution_clock::now();
#endif // LOCAL

    int tt, n;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        cout << '\n';
    }

#ifdef LOCAL
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
#endif // LOCAL

    return 0;
}

