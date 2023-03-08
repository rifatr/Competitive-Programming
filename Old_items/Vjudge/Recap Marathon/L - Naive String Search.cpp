#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    int i = 0, j, k, l;
    string line, word;

    cin >> line >> word;
//cout << line << " " << word;
    l = line.size();

    while(i < l) {
        size_t n = line.find(word, i);
        if (n != string::npos && n == i)
            cout << n << endl;
        i++;
    }
//main();
    return 0;
}
