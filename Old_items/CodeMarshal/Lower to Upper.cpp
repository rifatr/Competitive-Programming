#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, i, j;
    string s;

    //scanf("%d", &test);
    cin >> test;
    cin.ignore();

    for(i = 1; i <= test; i++) {
//        getchar();
//        scanf("%[^\n]s", name);

        getline(cin, s);

        for(j = 0; j < s.size(); j++) {
            if(s[j] >= 'a' && s[j] <= 'z')
                s[j] -= 32;
        }

        printf("Case %d: ", i);
        cout << s << endl;
    }

    return 0;
}
