#include<iostream>
#include<math.h>
#include<sstream>

using namespace std;

void findhum(double temp, double dew);
void findtemp(double dew, double hum);
void finddew(double temp, double hum);

double ep, h;

int main()
{

    string s;
    char T, D;
    double un1, un2;

    while(getline(cin, s) and s.size() > 1)
    {
        stringstream ss(s);
        ss >> T >> un1 >> D >> un2;

        if(T == 'T' and D == 'D')
            findhum(un1, un2);
        else if(T == 'D' and D == 'T')
            findhum(un2, un1);

        else if(T == 'D' and D == 'H')
            findtemp(un1, un2);
        else if(T == 'H' and D == 'D')
            findtemp(un2, un1);

        else if(T == 'T' and D == 'H')
            finddew(un1, un2);
        else
            finddew(un2, un1);
    }


    return 0;
}

void findhum(double temp, double dew)
{
    ep = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dew + 273.16))));
    h = 0.5555 * (ep - 10.0);
    double hum = temp + h;

    printf("T %.1lf D %.1lf H %.1lf\n", temp, dew, hum);
}

void findtemp(double dew, double hum)
{
    ep = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dew + 273.16))));
    h = 0.5555 * (ep - 10.0);
    double temp = hum - h;

    printf("T %.1lf D %.1lf H %.1lf\n", temp, dew, hum);
}

void finddew(double temp, double hum)
{
    h = hum - temp;
    ep = (h / 0.5555) + 10.0;
    double dew_in_kal = (1 / 273.16) - ((1 / 5417.7530) * log(ep / 6.11));

    double dew = (1 / dew_in_kal) - 273.16;

    printf("T %.1lf D %.1lf H %.1lf\n", temp, dew, hum);
}

