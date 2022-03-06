#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int A,B,count = 0;
        cin >> A >> B;
        for(int i = A;i <=B;i++)
        {
            string x = to_string(i);
            string mem = x;
            reverse(x.begin(),x.end());
            if(mem == x)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;

}