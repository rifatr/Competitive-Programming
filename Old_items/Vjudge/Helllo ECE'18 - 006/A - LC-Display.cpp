#include<bits/stdc++.h>

#define lop0(n) for(int i = 0; i < n; i++)
#define lop(n) for(int i = 1; i <= n; i++)
#define lopj(n) for(int j = 1; j <= n; j++)
#define scan(a, b) scanf("%d %d", &a, &b)
#define pspace cout << " "
#define phi cout << "-"
#define pd cout << "|"
#define pnl cout << '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

void zero(int s, int n);
void one(int s, int n);
void two(int s, int n);
void thri(int s, int n);
void four(int s, int n);
void fiv(int s, int n);
void six(int s, int n);
void sevn(int s, int n);
void eit(int s, int n);
void nine(int s, int n);

int main()
{
    int s, n, p;

    while(scan(s, n) and (s | n))
    {
        if(n == 0) {
            zero(s, n);
            pnl;
            continue;
        }

        vector <int> digits;

        while(n)
        {
            p = n % 10;
            n /= 10;

            digits.pb(p);
        }

        reverse(all(digits));

        int saiz = digits.size();
        lop0(saiz)
        {
            p = digits[i];

            if(p == 0)
                zero(s, n);
            else if(p == 1)
                one(s, n);
            else if(p == 2)
                two(s, n);
            else if(p == 3)
                thri(s, n);
            else if(p == 4)
                four(s, n);
            else if(p == 5)
                fiv(s, n);
            else if(p == 6)
                six(s, n);
            else if(p == 7)
                sevn(s, n);
            else if(p == 8)
                eit(s, n);
            else
                nine(s, n);
        }

        pnl;
    }

    return 0;
}

void zero(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if(i == (r / 2) + 1)
                pspace;
            else {
                if(j == 1 or j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void one(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(j == c) {
                if(i != 1 and i != r and i != (r / 2) + 1)
                    pd;
            }
            else
                pspace;
        }
        pnl;
    }
}

void two(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if (i <= r / 2) {
                if(j == c)
                    pd;
                else
                    pspace;
            }
            else {
                if(j == 1)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void thri(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else {
                if(j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void four(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r) {
                pspace;
            }
            else if (i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if (i <= r / 2) {
                if(j == c or j == 1)
                    pd;
                else
                    pspace;
            }
            else {
                if(j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void fiv(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if (i <= r / 2) {
                if(j == 1)
                    pd;
                else
                    pspace;
            }
            else {
                if(j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void six(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if (i <= r / 2) {
                if(j == 1)
                    pd;
                else
                    pspace;
            }
            else {
                if(j == c or j == 1)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void sevn(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if(j == c) {
                if(i != 1 and i != r and i != (r / 2) + 1)
                    pd;
            }
            else
                pspace;
        }
        pnl;
    }
}

void eit(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else {
                if(j == 1 or j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}

void nine(int s, int n)
{
    int r = (2 * s) + 3, c = s + 2;

    lop(r)
    {
        lopj(c)
        {
            if(i == 1 or i == r or i == (r / 2) + 1) {
                if(j == 1 or j == c)
                    pspace;
                else
                    phi;
            }
            else if (i <= r / 2) {
                if(j == 1 or j == c)
                    pd;
                else
                    pspace;
            }
            else {
                if(j == c)
                    pd;
                else
                    pspace;
            }
        }
        pnl;
    }
}
