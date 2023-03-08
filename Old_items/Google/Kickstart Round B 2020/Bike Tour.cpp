#include<bits/stdc++.h>

using namespace std;

int main()
{
int t, n, x;
vector<int>v;
cin >> t;

for(int i = 1; i <= t; i++)
{
cin >> n;
for(int j = 0; j < n; j++) {
    cin >> x;
    v.push_back(x);
}
int c =0;
for(int j = 1; j < n-1; j++) {
    if(v[j] > v[j - 1] && v[j] > v[j+1])
        c++;
}

printf("Case #%d: %d\n", i, c);

v.clear();

}

return 0;
}
