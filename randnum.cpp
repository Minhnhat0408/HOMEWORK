#include <iostream>
#include <algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<time.h>
using namespace std;

set <set<int>> triplenum(int*a,const int t,int size)
{   
    set <set<int>> ans;
    sort(a, a + size, greater<int>());
    for(int i = 0; i < size ; i++)
    {
        for(int j = i+1;j < size;j++)
        {
            for(int k = j+1;k< size;k++)
            {
                if((a[i] + a[j] + a[k])%t == 0)
                {
                    set <int> x = {a[i],a[j],a[k]};
                    ans.insert(x);
                }
            }
        }
    }
    return ans;
}
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    int a[n],range = 49;
    for(int i =0 ;i < n;i++)
    {
        a[i] = rand()%range;
        cout << a[i] << " ";
    }
    set <set<int>> out = triplenum(a,25,n);
    for(auto const &x:out)
    {
        for(auto const &a:x)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    

}