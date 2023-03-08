#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

float findStandardDeviation(float *array, int count);

int main() {
    int count, i;
    //float inputArray[500];

    while(1)
    {cout << "Enter number of elements\n";
    cin >> count;

    if(count == 0) break;
    float inputArray[count];
    cout << "Enter " << count <<" elements\n";
    for(i = 0; i < count; i++){
     cin >> inputArray[i];
    }

    cout << "Standard Deviation = " << fixed << setprecision(8) << findStandardDeviation(inputArray, count);}

    return 0;
}
// Function to find standard deviation
float findStandardDeviation(float *array, int count) {
    float sum = 0.0, sDeviation = 0.0, mean;
    int i;

    for(i = 0; i < count; i++) {
        sum += array[i];
    }
    // Calculating mean
    mean = sum/count;

    for(i = 0; i < count; ++i) {
        sDeviation += pow(array[i] - mean, 2);
    }

    return sqrt(sDeviation/count);
}
