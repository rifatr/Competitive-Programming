#include <bits/stdc++.h>

using namespace std;

#define MAX 100000000000000
long long saiz = 0;

struct styack
{
    char data;
    styack *next, * pre;
};

struct styack *tail, *tnb, *cb, *cur, *par, *tar;

bool push(char x)
{
    if(saiz >= MAX) {
        cout << "Sorry, Stack is Full\n";
        tail -> next = '\0';
    }
    else {
        tnb = (struct styack*) malloc(sizeof(struct styack));
        tnb -> data = x;
        if(saiz == 0) {
            tnb -> pre = '\0';
        }
        else {
            tail -> next = tnb;
            tnb -> pre = tail;// -> next;
        }
        tail = tnb;
        saiz++;
    }
}

void pop()
{
    if(saiz <= 0) {
        cout << "Sorry, Stack is Empty\n";
        free(tail);
    }

    else {
        saiz--;
        tail = tail -> pre;
        free(tail -> next);
    }
}

int empity()
{
    if(tail == NULL)
        return 1;
    else
        return 0;
}

char top()
{
    return tail -> data;
}

int main()
{
    int t, i;
    string s;

//    freopen("input_o.txt", "r", stdin);
//    freopen("output_o.txt", "w", stdout);

    cin >> t;
    cin.ignore();

    while(t--)
    {
        getline(cin, s);
        cin.ignore();

        styack q;

        for(i = 0; i < s.size(); i++)
        {
            if(0 == empity() && s[i] == ')' && top() == '(')
                pop();
            else if(0 == empity() && s[i] == ']' && top() == '[')
                pop();
            else if(s[i] != ' ')
                push(s[i]);
        }

        if(empity() == 1)
            cout << "Yes\n";
        else
            cout << "No\n";

        s.clear();
//        q.clear();
    }

    return 0;
}


