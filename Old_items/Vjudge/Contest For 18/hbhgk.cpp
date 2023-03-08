#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,c=0,d=0,e=0;
    vector<int>v;
    cin>>n;
    v.push_back(2);
    for(int i=3;i<=n;i+=2){
            c=0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                c=1;
            }
        }
    if(c==0){
        v.push_back(i);
    }
  }
//  for(int i=0;i<v.size();i++){
//    cout<<v[i]<<" ";
//  }
//  cout<<"\n";

  for(int i=1;i<=n;i++){
        d=0;e=0;
    for(int j=0;j<v.size();j++){
        if(i%v[j]==0){
            d++;
        }
        if(d==2){
        e++;
    }
    //cout<<d<<" ";

    }
   // cout<<e;
   // cout<<endl;
  }
  cout<<e<<endl;
  return 0;
}

