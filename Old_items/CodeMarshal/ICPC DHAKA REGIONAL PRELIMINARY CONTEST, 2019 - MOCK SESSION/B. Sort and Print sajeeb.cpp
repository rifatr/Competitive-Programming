#include<bits/stdc++.h>
    using namespace std;
    int main(){
        int r[200],marks[200],a;
        string na[200];
        cin >> a;
        getchar();//NEVER GET ANGRY
        for(int i=0;i<a;i++)
        {
            cin >> r[i];
            getchar();
            getline(cin,na[i]);
            cin >> marks[i];
            getchar();

        }


        for(int i=0;i<a-1;i++){
            for(int j=0;j<a-i-1;j++){
                if(marks[j]<marks[j+1]){
                    swap(marks[j],marks[j+1]);
                    swap(r[j],r[j+1]);
                    string temp = na[j];
                    na[j] = na[j+1];
                    na[j+1] = temp;


                }
                else if((marks[j]==marks[j+1]) && (r[j]>r[j+1])){
                    swap(r[j],r[j+1]);
                    string temp = na[j];
                    na[j] = na[j+1];
                    na[j+1] = temp;
                }
            }
        }
/*3
20
abul
0
7
babul
0
1
kabul
100*/
        cout << "Roll | Name       | Marks" << endl;
        cout << "-------------------------" << endl;
        for(int i=0;i<a;i++){
            cout << setw(4) << right << r[i] << " | ";
            cout << setw(10) << left << na[i] << " | ";
            cout << left << marks[i]  << endl;
        }
    return 0;
    }
