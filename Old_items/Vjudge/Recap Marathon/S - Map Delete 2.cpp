/*#include<bits/stdc++.h>
#include<map>

#define ll long long

using namespace std;

int main()
{
    map <string, ll> dic;
    string word;
    ll n, q, x, i;

    scanf("%lld", &q);

    for(i = 0; i < q; i++) {
     scanf("%lld", &n);
        if(n == 0)  {
            scanf("%s", word);
            getchar();
            scanf("%lld", &x);
            dic[word] = x;
        }
        else if(n == 1) {
            scanf("%s", word);
            getchar();
            auto it = dic.find(word);
            printf("%lld\n", it -> second);
        }
        else {
            scanf("%s", word);
            getchar();
            dic.erase(word);
        }
    }

    return 0;

}*/

#include <iostream>
#include <map>
 using namespace std;
int main()
{
    int n;
    map<int,char> example = {{1,'a'},{2,'b'},{3,'c'},{4,'d'},{5,'e'} };

    cout<<"Enter the element which you want to search: ";
    cin>>n;

    auto search = example.find(n);
    if (search != example.end()) {
        cout << n<<" found and the value is " << search->first << " = " << search->second << '\n';
    } else {
        cout << n<<" not found\n";
    }
}
