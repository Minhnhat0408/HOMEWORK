#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
    int r,c;
    cin>> r >> c;
    int i = 0,j = 0,add = 1,mr = r,mc = c;
    int arr[r][c],num = 1;
    while(r != 1 && c != 1)
    {
        for(j;j<c-1 && j >= mc-c;j+=add)
        {
            arr[i][j] = num;
            num++;
            cout << "j " << j <<" i " << i <<" ";
           
        }
        c--;
        for(i;i<r-1 && i >= mr-r;i+=add)
        {
            arr[i][j] = num;
            num++;
            cout << "j " << j <<" i " << i <<" ";

        }
        r--;
        add = -add;
    }
    cout << endl;
    for(int a= 0; a<mr;a++)
    {
        for(int b= 0;b < mc;b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
    

} 