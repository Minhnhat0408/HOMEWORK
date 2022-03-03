#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
    string line[5];
    line[0] = "*";
	for(int i= 1;i <5;i++ )
    {
        line[i] = '*' + line[i-1] +'*'; 
    }
    for(int i = 0; i < 5;i++)
    {
        while(line[i].size() < line[4].size())
        {
            line[i] = " "+line[i] + " ";
        }
        cout << line[i] << endl;
    }
} 
