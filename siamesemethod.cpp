#include <iostream>
#include <algorithm>
#include<iomanip>
#include<string.h>
using namespace std;

int main()
{	
    int n;
    cin >>n;
    int sia[n][n];
    for(int i = 0;i < n;i++) memset(sia,0,sizeof(sia));
    int i= 0,j =n/2,cnt = 2;
    sia[i][j] = 1;
    while(cnt <= n*n)
    {   
        i--;j++;
        int tmpi = i,tmpj = j;
        if(i < 0 ) tmpi+=n;
        if(j >=n) tmpj-=n;
        if(sia[tmpi][tmpj] == 0)
        {   
            i = tmpi;
            j = tmpj;
            sia[i][j] = cnt; 
        }else{
            i+= 2;
            j -=1;
            sia[i][j] = cnt;
        }
        cnt++;
    }
    for(int a= 0; a<n;a++)
    {
        for(int b= 0;b < n;b++)
        {
            cout << setw(3) << sia[a][b];
        }
        cout << endl;
    }
} 