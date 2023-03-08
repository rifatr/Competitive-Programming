#include<iostream>
using namespace std;
class A{
public:
    int x;
    void showA()
    {
        cout<<"From class A\n";
    }
};
class B: public A{
public:
    int y;
    void showB()
    {
                cout<<"From class B\n";
    }
};
class C{
    public:
    int z;
    void showC()
    {
                cout<<"From class C\n";
    }
};

int main()
{
   //A a1;

   B b1;
   C c1;
   cin>>b1.x;
   cin>>b1.y;
   c1.z=b1.x+b1.y;
   cout<<c1.z;
   b1.showA();
   b1.showB();
   c1.showC();
}
