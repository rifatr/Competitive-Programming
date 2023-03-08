#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
/* Infos */
~ 4 Direction
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
~ 8 Direction
int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};
~ Knight Direction
int dr[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dc[] = {2, 2, -2, -2, 1, -1, 1, -1};
~ Hexagonal Direction
int dr[] = {2, -2, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1};
~ bitmask operations
int Set(int n, int pos) { return n = n | (1 << pos); }
int reset(int n, int pos) { return n = n & ~(1 << pos); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
int toggle(int n, int pos) { return n = (n ^ (1 << pos));}
bool isPower2(int x) { return (x && !(x & (x - 1))); }
ll LargestPower2LessEqualX(ll x) { for (int i = 1; i <= x / 2; i *= 2) x = x | (x >> i); return (x + 1) / 2;}
// for unlimited stack, run the command in terminal and run the code in terminal
ulimit - s unlimited