#include<bits/stdc++.h>
using namespace std;
struct node
{
    char cdata;
    struct node *preadd;
    struct node *nextadd;
};

int main()
{
    struct node *cb,*tnb,*head,*par,*tar;
    cout<<"Choose an option"<<endl;
    cout<<"1.Traverse"<<endl<<"2.Insert"<<endl<<"3.Delete"<<endl;
    int n; cin>>n;
    tnb=(struct node*)malloc(sizeof(struct node) );
    cout<<"Insert elements"<<endl;
    tnb->cdata=getchar();

    head=tnb;
    while(1)
    {
        cb=tnb;
        tnb=(struct node*)malloc(sizeof(struct node) );
        tnb->cdata=getchar();
        tnb->preadd=cb;
        cb->nextadd=tnb;
        if(tnb->cdata=='\n')
        {
            tnb->nextadd='\0';break;
        }

    }
    cout<<"The elments are:"<<endl;

    head->preadd='\0';
    tnb=head;
    while(1)
    {
        cout<<tnb->cdata<<endl;
        cout<<"Its previous address:"<<tnb->preadd<<endl;
        cout<<"Its address:"<<tnb<<endl;
        cout<<"Its next address:"<<tnb->nextadd<<endl;
        if(tnb->nextadd=='\0')
        {
            break;
        }
        else tnb=tnb->nextadd;
    }



}
