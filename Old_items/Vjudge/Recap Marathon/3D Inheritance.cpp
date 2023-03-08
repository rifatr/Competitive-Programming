#include<iostream>

using namespace std;

class A
{
public:
    showA()
    {
        cout << "Show class A\n";
    }
};
class B : public A
{
public:
        showB()
        {
            cout << "Show class B\n";
        }
};



int main()
{
    B b1;
    b1.showA();

    return 0;
}
