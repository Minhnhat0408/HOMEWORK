#include <iostream>
#include <algorithm>
#include<math.h>
#include<vector>
using namespace std;

int rnd(double x)
{
    if(x- floor(x) > ceil(x) - x)
    {
        return ceil(x);
    }else{
        return floor(x);
    }
}

int rnd2(double x)
{
    double a = x - (int)x;
    if(a > 0.5)
    {
        return (int)x +1;
    }else{
        return (int)x;
    }
}

int main(){

    double a = 5.7;
    cout << rnd2(a);
}