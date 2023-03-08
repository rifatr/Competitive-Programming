#include<stdio.h>
#include<math.h>

int main()
{
    unsigned long long n,m,s, b, e;
    int i,  sum = 0, c = 3;
    scanf("%llu %llu", &n, &m);
    if(n < m) {
        s = n;
        b = m;
    }
    else {
        s = m;
        b = n;
    }
    int arr[c];
    for(i = 0; i * i <= s; i++) {

        if((n % i == 0) && (i != n / i)) {
           arr[c] = i;
           //arr[c+1] = n / i;
           c++;
        }
    }
    for(i = 0; i < c; i++)
        printf("%d ", arr[i]);
    return 0;
}
