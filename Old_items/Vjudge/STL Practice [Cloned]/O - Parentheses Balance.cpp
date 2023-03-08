#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, bracket_1s, bracket_1e, bracket_2s, bracket_2e, flag, k;
    char l;
    freopen("input_o.txt", "r", stdin);
   // freopen("output_o.txt", "w", stdin);

    cin >> t;
    cin.ignore();

    while(t--)
    {
        char line[130];
        for(j = 0, k = 0; ; j++) {
            scanf("%c", &l);
            if(l != ' ') {
                line[k] = l;
                k++;
            }
            if(l == '\n') {
                line[k] = '\0';
                break;
            }
        }
        k--;
//cout << k << endl;
        bracket_1s = 0;
        bracket_1e = 0;
        bracket_2s = 0;
        bracket_2e = 0;
        flag = 1;

        if(k == 0)
        {
            cout << "Yes\n";
            continue;
        }

//        if(k % 2 != 0)
//        {
//            cout << "No\n";
//            continue;
//        }

        for(i = 0; i < k; i++)
        {
            if(line[i] == '(')
                bracket_1s++;
            else if(line[i] == ')')
            {
                bracket_1e++;
                if(bracket_1e > bracket_1s)
                {
                    flag = 0;
                    break;
                }
            }
            else if(line[i] == '[')
                bracket_2s++;
            else if(line[i] == ']')
            {
                bracket_2e++;
                if(bracket_2e > bracket_2s)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if((line[0] == '(' && line[k - 1] == ')') || (line[0] == '[' && line[k - 1] == ']'))
            flag = 1;
        else
            flag = 0;

        if(bracket_1s == bracket_1e && bracket_2s == bracket_2e && flag == 1)
            cout << "Yes\n";
        else
            cout << "No\n";

        //line.clear();
    }

    return 0;
}

