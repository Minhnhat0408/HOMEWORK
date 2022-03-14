#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


void reset(int& a,int min,int max)
{
    if(a >= max) a = max-1;
    if(a < min) a = min;
}
int main()
{	
    int r,c;
    cin>> r >> c;
    int i = 0,j = 0,add = 1,rt = 0,rb = r,cl = 0,cr = c;
    int arr[r][c],num = 1;
    while(rt != rb && cl != cr)
    {   
        for(j;j<cr && j >= cl;j+=add)
        {
            arr[i][j] = num;
            num++;
        }
        if(add > 0)
        {
            rt++;
        }else{
            rb--;
        }
        
        reset(i,rt,rb);
        reset(j,cl,cr);
        
        for(i;i<rb && i >= rt;i+=add)
        {
            arr[i][j] = num;
            num++;
        }
        if(add > 0)
        {
            cr--;
        }else{
            cl++;
        }
        reset(i,rt,rb);
        reset(j,cl,cr);
        add = -add;
    }
    cout << endl;
    for(int a= 0; a<r;a++)
    {
        for(int b= 0;b < c;b++)
        {
            cout << setw(3) << arr[a][b];
        }
        cout << endl;
    }
    

} 