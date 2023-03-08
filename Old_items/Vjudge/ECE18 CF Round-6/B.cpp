#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"


int cap(string s)
{
    int k = 0;

    for(auto &z : s)
        if(z >= 'A' and z <= 'Z')
            k++;
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int n, s = 0;
    string txt, wrd;

    cin >> n;
    cin.ignore();
    getline(cin, txt);

    stringstream ss(txt);

    while(ss >> wrd)
        s = max(s, cap(wrd));

    cout << s << '\n';

    return 0;
}

