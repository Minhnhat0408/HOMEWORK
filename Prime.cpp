#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int x;
    cin >> x;
    bool check = true;
    if(x ==1 )
    {
        cout << "Yes";
    }else{
        for(int i = 2 ; i*i <= x;i++)
        {
            if(x%i == 0)
            {
                check = false;
                break;
            }
        } 
    }
    if(check)
    {
        cout << "Yes";
    }else{
        cout << "No";
    }
    
} 
