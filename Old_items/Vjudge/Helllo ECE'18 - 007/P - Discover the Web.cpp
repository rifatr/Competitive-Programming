#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int test;
    string command, link, cmd1, cmd2, cmd3, cmd4, ignore_msg, homepage;

    cmd1 = "BACK";
    cmd2 = "FORWARD";
    cmd3 = "FORWARD";
    cmd4 = "QUIT";
    ignore_msg = "Ignored";
    homepage = "http://www.lightoj.com/";

    cin >> test;

    lopj(0, test)
    {
        printf("Case %d:\n", j + 1);

        int x = 0;
        list <string> history;
        auto position = history.begin(), pew = position;

        history.insert(position, homepage);
        position--;

//        history.erase(pew);
//        cout << *history.begin();


        while(cin >> command and command != cmd4)
        {
            auto x = position;

            if(command == cmd1) {
                if(position == history.begin())
                    cout << ignore_msg << '\n';

                else {
                    cout << *--position << '\n';
                }
            }

            else if(command == cmd2) {
                if(++x == history.end()) {
                    cout << ignore_msg << '\n';
                }

                else {
                    cout << *++position << '\n';
                }
            }

            else {
                cin >> link;
                history.insert(++x, link);
                position++;

                cout << *position << '\n';

                history.erase(x, history.end());
            }

        }
    }

    return 0;
}

