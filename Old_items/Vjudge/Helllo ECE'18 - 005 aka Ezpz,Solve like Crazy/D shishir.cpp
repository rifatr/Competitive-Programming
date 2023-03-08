#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
int main()
{
    unsigned long long n,k;
    vector<unsigned long long>v;
    cin>>n>>k;
    //cout<<n<<k;
    while(1)
    {
        if((n-k)<0)
        {
           n=(n-k)*(-1);
        }
        else
            n=n-k;
        if(v.size()==0){
             v.push_back(n);
        }
        else{
        if(count(v.begin(),v.end(),n))
        {
            break;
        }
        else
        v.push_back(n);}
    }
    vector<unsigned long long>::iterator it;
    it=min_element(v.begin(),v.end());
    cout<<*it<<endl;
}
