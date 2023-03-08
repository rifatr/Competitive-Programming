#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    unsigned long long n, m, b, i, j, sum = 0, x, y;
    vector <unsigned long long> divn, divm, sm, bg;

    scanf("%llu %llu", &n, &m);

    if(n > m)
        b = n;
    else
        b = m;

    for(i = 1; i * i <= b; i++) {
        if(n % i == 0) {
            if(i != n / i) {
                divn.push_back(i);
                divn.push_back(n / i);
            }
            else
                divn.push_back(i);
        }
        if(m % i == 0) {
            if(i != m / i) {
                divm.push_back(i);
                divm.push_back(m / i);
            }
            else
                divm.push_back(i);
        }
    }

    sort(divn.begin(), divn.end());
    sort(divm.begin(), divm.end());

    x = divn.size();
    y = divm.size();

    if(x > y) {
        sm = divm;
        bg = divn;
    }
    else {
        sm = divn;
        bg = divm;
    }

    for(i = 0; i < divn.size(); i++) {
        cout << divn.at(i) << ' ';
    } cout << endl;
    for(i = 0; i < divm.size(); i++) {
        cout << divm.at(i) << ' ';
    } cout << endl;

    for(i = 0, j = 0; i < bg.size(); i++) {
        if(bg[i] == sm[j]) {
            sum += bg[i];
            j++;
        }
    }

//    for(i = 0; i < divn.size(); i++) {
//        if(divn[i] == divn[i + 1])
//            continue;
//        for(j = 0; j < divm.size(); j++) {
//            if(divn[i] == divm[j]) {
//                sum += divn[i];
//                break;
//            }
//        }
//    }
    printf("%llu\n", sum);

    return 0;
}
