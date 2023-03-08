#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, vote, min_vote, total_vote = 0;
    vector <int> items;

    cin >> n >> m;

    for(i = 0; i < n; i++) {
        cin >> vote;
        items.push_back(vote);
        total_vote += vote;
    }

    min_vote = ceil(total_vote / (4.0 * m));

    //cout << min_vote << endl;

    sort(items.begin(), items.end(), greater <int> ());

    if(items[m - 1] >= min_vote)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
