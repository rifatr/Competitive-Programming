#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, j, TJ, si, log;
    string fd;

    cin >> t;

    while(t--)
    {
        TJ = 0; si = 0; log = 0;
        cin >> n;
        cin.ignore();
        cin >> fd;
        for(j = 0; j < n;)
        {
            if(fd[j] == 'T') {
                TJ++;
                j += 2;
            }
            else if(fd[j] == 's') {
                si++;
                j += 2;
            }
            else {
                log++;
                j += 3;
            }
        }
        printf("%d %d %d\n", TJ, si, log);
        fd.clear();
    }

    return 0;
}
