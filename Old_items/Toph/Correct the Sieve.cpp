#include <bits/stdc++.h>

using namespace std;

int isPrime[ 1000007 ] ;
void sieve() {

    int l = sqrt(1000006);

    isPrime[1] = 1;

	for( int i = 4 ; i <= 1000006 ; i += 2 ) {
		isPrime[ i ] = 1 ;
	}
	for( int i = 3 ; i <= 1000000 ; i ++ ) {
        if(i <= l) {
            for( int j = i * i ; j <= 1000006 ; j += i * 2) {
                isPrime[ j ] = 1 ;
            }
        }
	}
}
int main() {
	sieve() ;
	int N ;
	scanf("%d",&N) ;
	int num ;
	for( int i = 0 ; i < N ; i ++ ) {
		scanf("%d",&num) ;
		if( isPrime[ num ] == 0 ) {
			printf("%d is a prime number.\n",num);
		}
		else {
			printf("%d is not a prime number.\n",num);
		}
	}
	return 0 ;
}
