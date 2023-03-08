#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(ll i = 0; i < n; i++)

using namespace std;

struct contestant
{
    ll time, tried[10], submission, solve;
    char verdict[10];
};

struct standings
{
    ll id, solved, penalty;

    bool operator < (const standings &b) const
    {
        if(solved == b.solved)
        {
            if(penalty == b.penalty)
                return id < b.id;
            else
                return penalty < b.penalty;
        }
        else
            solved > b.solved;
    }
};

int main()
{
    freopen("B input.txt", "r", stdin);

    ll testcase, caseno = 1;

    cin >> testcase;
    cin.ignore();
    string bal;
    getline(cin, bal);

    while(caseno <= testcase)
    {
        ll ID, prb, taim;
        char v;
        contestant person[101];
        vector <standings> contest;
        string s;

        lop(101) {
            person[i].solve = person[i].submission = person[i].time = 0;

            for(ll j = 0; j < 10; j++) {
                person[i].tried[j] = 0;
                person[i].verdict[j] = ' ';
            }
        }

        while(getline(cin, s) and s.size()) {
            stringstream ss(s);
            ss >> ID >> prb >> taim >> v;

            //printf("%lld %lld %lld %c\n", ID, prb, taim, v);

            person[ID].submission++;

            if(person[ID].verdict[prb] == 'C')
                continue;

            person[ID].verdict[prb] = v;

            if(v == 'I')
                person[ID].tried[prb]++;

            else if(v == 'C')
            {
                person[ID].time += taim + (20 * person[ID].tried[prb]);
                person[ID].solve++;
            }

            else
                continue;
        }

        standings tmp;

        lop(101)
        {
            if(person[i].submission > 0)
            {
                tmp.id = i;
                tmp.solved = person[i].solve;
                tmp.penalty = person[i].time;

                contest.push_back(tmp);
            }
        }

        sort(contest.begin(), contest.end());

        //cout << "case " << caseno << '\n';

        ll n= contest.size();
        lop(n)
            cout << contest[i].id << " " << contest[i].solved << " " << contest[i].penalty << '\n';

        if(caseno < testcase)
            cout << '\n';
        caseno++;

        //cout << "case " << caseno << '\n';
    }

    return 0;
}

//core i3 7/8gen
//ram 4
//hdd 1tb
