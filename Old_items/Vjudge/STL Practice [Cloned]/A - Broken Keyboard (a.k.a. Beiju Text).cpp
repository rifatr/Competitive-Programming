#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, index, l, l2, l3, k;
    //string :: iterator it;

    string line;

    while(getline(cin, line))
    {
        list <char> line2;
        list <char> :: iterator it = line2.begin();

        for(i = 0; i < line.size(); i++)
        {
            if(line[i] == '[')
                it = line2.begin();
            else if(line[i] == ']')
                it = line2.end();
            else
                line2.insert(it, line[i]);
        }
        for(it = line2.begin(); it != line2.end(); it++)
            cout << *it;

        cout << endl;

        line.clear();
        line2.clear();
    }
}
