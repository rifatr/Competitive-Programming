#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t,i,j,flag=0,w=0;
    scanf("%d %d ",&s,&t);
    char n1[s],n2[t];
    for(i=0; i<s; i++)
    {
        cin>>n1[i];
    }
    for(j=0; j<t; j++)
    {
        cin>>n2[j];
    }
    if(s>t+1)
    {
        flag++;
    }
    for(i=0; i<s; i++)
    {
        if(n1[i]=='*')
        {
            w++;
        }
    }
    if(w==0)
    {
        for(i=0,j=0; n2[j]!='\0'; i++,j++)
        {
            if(n1[i]!=n2[j])
            {
                flag++;
            }
        }
    }
    else
    {
        for(i=0,j=0; n1[i]!='*'; i++,j++)
        {
            if(n1[i]!=n2[j])
            {
                flag++;
            }
        }
        for(i=s-1,j=t-1; n1[i]!='*'; i--,j--)
        {
            if(n1[i]!=n2[j])
            {
                flag++;
            }
        }
    }
    if(flag==0)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0;
}
