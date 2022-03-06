#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int main()
{	
	// int n = 0;
    // cin >> n;
    // while(n != -1)
    // {
        
    //     int a  = (n%5 == 0) ? n/5:-1;
    //     cout << a << endl;
    //     cin >> n;
    // }
    // cout << "Bye";
    // return 0;
    int row,col;

    cin >> row>>col;
    int mine[row+2][col+2];
    for(int i =0;i < row+2;i++)
    {
        memset(mine[i],0,sizeof(mine[i]));
    }
    for(int i =1;i < row+1;i++)
    {
        for(int j = 1;j< col+1;j++)
        {   
            char x;
            cin >> x;
            if(x == '*')
            {
                mine[i][j] = -10;
                mine[i+1][j]++;
                mine[i-1][j]++;
                mine[i][j+1]++;
                mine[i][j-1]++;
                mine[i+1][j+1]++;
                mine[i+1][j-1]++;
                mine[i-1][j+1]++;
                mine[i-1][j-1]++;
            }
        }
    }
    for(int i =1;i < row+1;i++)
    {
        for(int j = 1;j< col+1;j++)
        {
            if(mine[i][j] < 0)
            {
                cout << '*' << " ";
            }else{
                cout << mine[i][j]<< " ";
            }
        }
        cout << endl;
    }
} 