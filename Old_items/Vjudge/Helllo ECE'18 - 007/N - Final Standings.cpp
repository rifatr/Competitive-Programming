#include<bits/stdc++.h>

#define lop(n) for(int i = 0; i < n; i++)

#define fread freopen("input.txt", "r", stdin)
#define fwrite freopen("output.txt", "w", stdout)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

struct contestant
{
    int id, solved_problem;

    bool operator < (const contestant &b) const
    {
        return solved_problem > b.solved_problem;
    }
};

int main()
{
    //fastio;

    int tt, n;

    cin >> tt;

    contestant contestants[tt];

    lop(tt) cin >> contestants[i].id >> contestants[i].solved_problem;

   stable_sort(contestants, contestants + tt);

    lop(tt) cout << contestants[i].id << " " << contestants[i].solved_problem << '\n';

    return 0;
}

