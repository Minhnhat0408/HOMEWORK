#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int findExtra(int a[],int b[],int sizea)
{
   for(int i =0;i <sizea;i++ )
   {
       if(a[i] != b[i])
       {
            return b[i];
       }
   }
}
int main()
{	
   int n;
   cin >> n;
   int a[n],b[n+1];
   for(int i =0; i < n;i++)
   {
       cin >> a[i];
   } 
   for(int i =0; i < n+1;i++)
   {
       cin >> b[i];
   } 
   sort(a,a+n);
   sort(b,b+n);
   cout << findExtra(a,b,n);

} 