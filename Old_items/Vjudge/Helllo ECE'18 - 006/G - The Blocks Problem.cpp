#include<bits/stdc++.h>

#define scan(a) scanf("%d", &a)
#define scans(a) scanf("%s", &a)
#define lop(n) for(int i = 0; i < n; i++)
#define lopr(r, n) for(int i = r; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define pub push_back
#define puf push_front
#define pb pop_back
#define pf pop_front
#define all(i, x) x[i].begin(), x[i].end()

using namespace std;

int main()
{
    freopen("G input.txt", "r", stdin);

    int n, a, b;
    char o[4], d[4];

    scan(n);

    deque <int> block[n];

    lop(n) block[i].pub(i);

    while(scans(o) and strcmp(o, "quit"))
    {
        scan(a); scans(d); scan(b);

        if(strcmp(o, "move"))
        {
            if(strcmp(d, "onto"))
            {
                int bna, posa, bnb, posb;

                lop(n) //finding 'a' started
                {
                    auto it = lower_bound(all(i, block), a);
                    if(*it == a) { //found
                        bna = i; //block_number
                        posa = it - block[i].begin(); //index of 'a'
                        break;
                    }
                } //finding 'a' finished

                int saiz = block[bna].size(); //all elements of block a initializing started
                lopr(posa + 1, saiz)
                {
                    int x = block[bna][i];
                    block[x].puf(x);
                } //all elements of block a initializing finished

                auto it = posa + 1 + block[bna].begin();
                block[bna].erase(it, block[bna].end());

                lop(n) //finding 'b' started
                {
                    auto it = lower_bound(all(i, block), b);
                    if(*it == b) { //found
                        bnb = i; //block_number
                        posb = it - block[i].begin(); //index of 'a'
                        break;
                    }
                } //finding 'b' finished

                saiz = block[bnb].size(); //all elements of block b initializing started
                lopr(posb + 1, saiz)
                {
                    int x = block[bnb][i];
                    block[x].puf(x);
                } //all elements of block b initializing finished

                it = posb + 1 + block[bnb].begin();
                block[bnb].erase(it, block[bnb].end());

                block[bnb].pub(a); // moving a onto b
                block[bna].pb(); // clear a from old position

            }

            else
            {
                int bna = -1, posa, bnb = -1, posb;

                lop(n) //finding a, b started
                {
                    if(bna == -1) {
                        auto it = lower_bound(all(i, block), a);
                        if(*it == a) { //found
                            bna = i; //block_number
                            posa = it - block[i].begin(); //index of 'a'
                        }
                    }

                    if(bnb == -1) {
                        auto it = lower_bound(all(i, block), b);
                        if(*it == b) { //found
                            bnb = i; //block_number
                            posb = it - block[i].begin(); //index of 'a'
                        }
                    }
                } //finding a, b finished

                int saiz = block[bna].size(); //all elements of block a initializing started
                lopr(posa + 1, saiz)
                {
                    int x = block[bna][i];
                    block[x].puf(x);
                } //all elements of block a initializing finished

                auto it = posa + block[bna].begin();
                block[bna].erase(it, block[bna].end());

                block[bnb].pub(a); // moving a onto b
            }
        }

//        else
//        {
//            if(strncmp(d, "onto"))
//            {
//
//            }
//            else
//            {
//
//            }
//        }

        lop(n)
    {
        int saiz = block[i].size();

        printf("%d:", i);

        lopj(saiz)
            printf(" %d", block[i][j]);

        printf("\n");
    }
    }

    lop(n)
    {
        int saiz = block[i].size();

        printf("%d:", i);

        lopj(saiz)
            printf(" %d", block[i][j]);

        printf("\n");
    }

    return 0;
}
