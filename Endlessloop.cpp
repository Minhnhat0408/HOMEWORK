#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int n = 0;
    cin >> n;
    while(n != -1)
    {
        
        int a  = (n%5 == 0) ? n/5:-1;
        cout << a << endl;
        cin >> n;
    }
    cout << "Bye";
    return 0;

} 