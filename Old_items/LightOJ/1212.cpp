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

    int test, input, total_command, saiz;
    string command, command1, command2, command3, command4, full_msg, empty_msg, cmd1_msg, cmd2_msg, cmd3_msg, cmd4_msg;

    command1 = "pushLeft";
    command2 = "pushRight";
    command3 = "popLeft";
    command4 = "popRight";
    full_msg = "The queue is full";
    empty_msg = "The queue is empty";
    cmd1_msg = "Pushed in left: ";
    cmd2_msg = "Pushed in right: ";
    cmd3_msg = "Popped from left: ";
    cmd4_msg = "Popped from right: ";

    cin >> test;

    lopj(0, test)
    {
        printf("Case %d:\n", j + 1);

        cin >> saiz >> total_command;

        deque <int> que;

        lop(0, total_command)
        {
            cin >> command;

            int x = que.size();

            if(command == command1) {
                cin >> input;

                if(x == saiz)
                    cout << full_msg << '\n';
                else {
                    que.push_front(input);
                    cout << cmd1_msg << input << '\n';
                }
            }

            else if(command == command2) {
                cin >> input;

                if(x == saiz)
                    cout << full_msg << '\n';
                else {
                    que.push_back(input);
                    cout << cmd2_msg << input << '\n';
                }
            }

            else if(command == command3) {
                if(x == 0)
                    cout << empty_msg << '\n';
                else {
                    input = que[0];
                    que.pop_front();
                    cout << cmd3_msg << input << '\n';
                }
            }

            else if(command == command4) {
                if(x == 0)
                    cout << empty_msg << '\n';
                else {
                    input = que[x - 1];
                    que.pop_back();
                    cout << cmd4_msg << input << '\n';
                }
            }
        }
    }

    return 0;
}

