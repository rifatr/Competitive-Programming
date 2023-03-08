#include<bits/stdc++.h>

using namespace std;

string close = "END_OF_TEXT";

string up(string s)
{
	int n = s.size();

	for(int i = 0; i < n; i++)
	{
		if(s[i] >= 'a' and s[i] <= 'z')
			continue;

		if(s[i] >= 'A' and s[i] <= 'Z')
			s[i] += 32;

		else
			s[i] = ' ';
	}

	return s;
}

int main()
{
   string s, line, word;
   int c = 0;

   cin >> s;
   s = up(s);

   while(getline(cin, line) and line != close)
   {

   		line = up(line);
   		stringstream ss(line);

   		while(ss >> word) {
   			if(word == s) {
   				c++;

            cout << word << endl;
   			}
   		}
   }

   cout << c << '\n';

   return 0;
}
