#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("272 input.txt", "r", stdin);

    string line, word;
    list <string> tex;
    list <string> ::iterator it = tex.end();
    int c = 0;

    while(getline(cin, line))
    {
        string s;

        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '"') {
                if(c % 2 == 0) {
                    tex.insert(it, s);
                    tex.insert(it, "``");
                    s = "";
                    c++;
                }
                else {
                    tex.insert(it, s);
                    tex.insert(it, "''");
                    s = "";
                    c++;
                }
            }
            else
                s += line[i];
        }

        if(s != "") tex.insert(it, s);

        tex.insert(it, "\n");
    }

    for(auto &z : tex) cout << z;
    //cout << '\n';

    return 0;
}

