#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define print(s) cout << s << '\n'
#define ignore cout << "Ignored\n"

string vist = "VISIT", back = "BACK", forw = "FORWARD", quit = "QUIT";
string home = "http://www.lightoj.com/";

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ":\n";
        string url, cmd;
        stack <string> st1, st2;
        st1.push(home);

        while (1)
        {
            cin >> cmd;
            if (cmd == quit) break;

            if (cmd == back)
            {
                if (st1.empty())
                    ignore;
                else
                {
                    url = st1.top();
                    st1.pop();
                    if (!st1.empty())
                        st2.push(url);
                    if (st1.empty())
                    {
                        st1.push(home);
                        ignore;
                    }
                    else
                        print(st1.top());
                }
            }
            else if (cmd == forw)
            {
                if (st2.empty())
                    ignore;
                else
                {
                    url = st2.top();
                    st2.pop();
                    st1.push(url);
                    print(url);
                }
            }
            else if (cmd == vist)
            {
                cin >> url;

                st1.push(url);
                print(url);
                while (!st2.empty()) st2.pop();
            }
        }

    }

    return 0;
}
