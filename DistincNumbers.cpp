#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int n,mem;
    while(n>=0)
    {
        cin >> n;
        if(mem != n && n >=0)
        {
            cout << n << " ";
            mem = n;
        }
    }

} 