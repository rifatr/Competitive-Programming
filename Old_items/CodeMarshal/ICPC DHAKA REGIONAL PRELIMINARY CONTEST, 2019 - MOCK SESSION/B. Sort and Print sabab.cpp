#include<bits/stdc++.h>
using namespace std;

struct st
{
    int roll;
    string name;
    float mark;
};

int main()
{
    int T;
    cin>>T;
    struct st s[T];

    for(int i=0; i<T; i++)
    {
        cin>>s[i].roll>>s[i].name>>s[i].mark;
    }
    for(int j=0; j<T; j++)
    {
        for(int i=0; i<T-1; i++)
        {
            if(s[i].mark<s[i+1].mark)
            {
                swap(s[i].mark,s[i+1].mark);
                swap(s[i].roll,s[i+1].roll);
                swap(s[i].name,s[i+1].name);
            }
            else if(s[i].mark==s[i+1].mark)
            {
                if(s[i].roll>s[i+1].roll)
                {
                    swap(s[i].mark,s[i+1].mark);
                    swap(s[i].roll,s[i+1].roll);
                    swap(s[i].name,s[i+1].name);
                }
            }
        }
    }

    printf("Roll | Name       | Marks\n");
    printf("-------------------------\n");
    for(int i=0; i<T; i++)
    {
        if(s[i].roll<10)cout<<"   ";
        else if(s[i].roll<100)cout<<"  ";
        cout<<s[i].roll<<" | "<<s[i].name<<"      | "<<s[i].mark<<endl;
    }

}

