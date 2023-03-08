#include<bits/stdc++.h>

using namespace std;

#define ll long long

/*struct dim {
    ll a[0];

    bool operator<(const dim& p) const
    {
        return a[0] > p.a[0]; 
    }
};
struct dim2 {
    ll a[2];

    bool operator<(const dim2& p) const
    {
        if(a[0] == p.a[0])
            
            return a[1] > p.a[1];
        else
            return a[0] > p.a[0];
    }
};
struct dim3 {
    ll a[3];

    bool operator<(const dim3& p) const
    {
        if(a[0] == p.a[0])
        {
            if(a[1] == p.a[1])
                return a[2] > p.a[2];
            else
                return a[1] > p.a[1];
        }
        else
            return a[0] > p.a[0];
    }
};
struct dim4 {
    ll a[4];

    bool operator<(const dim4& p) const
    {
        if(a[0] == p.a[0])
        {
            if(a[1] == p.a[1])
            {
                if(a[2] == p.a[2])
                    return a[3] > p.a[3];
                else
                    return a[2] > p.a[2];
            }
            else
                return a[1] > p.a[1];
        }
        else
            return a[0] > p.a[0];
    }
};*/
struct dim5 {
    ll a[5];

    bool operator<(const dim5& p) const
    {
        if(a[0] == p.a[0])
        {
            if(a[1] == p.a[1])
            {
                if(a[2] == p.a[2])
                {
                    if(a[3] == p.a[3])
                        return a[4] < p.a[4];
                    else
                        return a[3] > p.a[3];
                }
                else
                    return a[2] > p.a[2];
            }
            else
                return a[1] > p.a[1];
        }
        else
            return a[0] > p.a[0];
    }
};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, D;

    cin >> N >> D;
    
    /*if(D == 1)
        dim P[N];
    else if (D == 2)
        dim2 P[N];
    else if (D == 3)
        dim3 P[N];
    else if (D == 4)
        dim4 P[N];
    else
        dim5 P[N];*/

    dim5 P[N];


    for(int i = 0; i < N; i++)
        for(int j = 0; j < D; j++)
            cin >> P[i].a[j];

    sort(P, P + N);

    ll mst = 0;

    /*for(int i = 0; i < N; i++)
    {    
        for(int j = 0; j < D; j++)
            cout << P[i].a[j] << ' ';
        cout << endl;
    }*/
    
    for(int i = 0; i < N - 1; i++)
    {   
        for(int j = 0; j < D; j++)
            mst += P[i].a[j] - P[N - 1].a[j];
        //cout << mst << ' ';
    }


    cout << mst << endl;

    return 0;
}
