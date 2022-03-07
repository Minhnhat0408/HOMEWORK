#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int main()
{	
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int si;
        cin >> si;
        int arr[si];
        cin >> arr[0];
        bool check =false;
        for(int j =1; j < si;j++)
        {
            int tmp;
            cin >> tmp;
            arr[j] = arr[j-1]+tmp;
            

        }
        for(int j =0 ;j < si;j++)
        {   
            int TL;
            if(j == 0)
            {
                TL = 0;
            }else{
                TL = arr[j-1];
            }
            int TR = arr[si-1] - arr[j];
            if( TL == TR)
            {
                check = true;
            }
        }
        if(check)
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
} 