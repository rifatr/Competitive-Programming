#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;

    while(getline(cin, line))
    {
        int n = line.size();
        list <char> Beiju_text;
        auto position = Beiju_text.end();

        lop(0, n)
        {
            if(line[i] == '[')
                position = Beiju_text.begin();

            else if(line[i] == ']')
                position = Beiju_text.end();

            else
                Beiju_text.insert(position, line[i]);
        }

        for(auto &z : Beiju_text)
            cout << z;

        cout << '\n';
    }

    return 0;
}

