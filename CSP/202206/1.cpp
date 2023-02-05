#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1010;
double a[N];
int n;
int main()
{
    cin>>n;
    double sum = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        sum += a[i];
    }
    double avg = sum / n;
    double d = 0.0;
    for(int i = 0;i < n;i++){
        d += (a[i] - avg) * (a[i] - avg);
    }
    d /= n;
    d = sqrt(d);
    for (int i = 0; i < n; i++) {
        double x = (a[i] - avg) / d;
        printf("%.8f\n", x);
    }
    return 0;
}
