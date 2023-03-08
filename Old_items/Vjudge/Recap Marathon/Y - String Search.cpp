#include<bits/stdc++.h>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    int i, j, k, l, m, n;
    char line[1000002], word[10002];

    scanf(" %s", line);
    //getchar( );
    scanf(" %s", word);
    //printf("%s %s\n", line , word);

    m = strlen(line);
    n = strlen(word);

  for(i = 0; i < m; i++)
  {
    if(strncmp(&line[i], word, n) == 0)

      printf("%d\n",    i);

  }
//main();
    return 0;
}
