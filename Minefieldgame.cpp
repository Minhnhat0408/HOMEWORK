#include <iostream>
#include <algorithm>
#include<string.h>
#include<vector>
using namespace std;

void mGame(int r,int c,int *map,bool& status)
{
    
}
int main()
{   
    /* * * * * *
     * * * * 4 * 
     * * 5 * * *
    */
    int row,col;
    bool gameOver = false;
    cin >> row>>col;
    int mine[row+2][col+2];
    string map[row][col];
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
            map[i-1][j-1] = "#";
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
    while(!gameOver)
    {
        int x,y;
        cin >> x >> y;
        for(int i =1;i < row+1;i++)
        {
            for(int j = 1;j< col+1;j++)
            {   
               if(i -1 == y && j-1 == x)
               {   
                   if(mine[i][j] <0)
                   {
                        map[y][x] = "@";
                        gameOver = true;
                        cout << map[y][x] << " ";
                   }else{
                        map[y][x] = to_string(mine[i][j]);
                        cout << map[y][x] << " ";
                   }
               }else {
                    cout << map[i-1][j-1] << " ";
               } 
            }
            cout << endl;
        }
    }
    
}