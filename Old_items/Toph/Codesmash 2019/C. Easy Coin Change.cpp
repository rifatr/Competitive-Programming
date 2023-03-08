#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, n, v, k, t, inp, sum;
    vector <int> v1, v2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &k, &v);
        while(n--) {
            scanf("%d", &inp);
            v1.push_back(inp);
        }
        v2 = v1;
        for(i = 0; i < v1.size(); i++) {
            for(j = 0; j < v1.size(); j++) {
                inp = v1.at(i) + v1.at(j);
                v2.push_back(inp);
            }
        }

        inp = 0;
        sort(v2.begin(), v2.end());
        for(i = 0; i < v2.size() - 1; i++) {
            if(v2[i] != v2[i+1] && v2[i] < v) {
                inp++;
               // printf("%d\n", v2[i]);
            }

        }
        printf("%d\n", inp);
        v1.clear();
        v2.clear();
    }
}
