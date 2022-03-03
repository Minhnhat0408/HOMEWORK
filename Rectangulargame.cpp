#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


bool Timlap(int* arr){
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    for(int i = 0;i < n; i++)
    {
        if(arr[i] == arr[i+1])
        {
            return true;
        }
    }
    return true;
    
}

bool symetricalstr(string n)
{
    string std = n;
    reverse(n.begin(),n.end());
    if(std == n)
    {
        return true;
    }
    return false;
}
int main()
{   
    string a;
    cin >> a;
    if(symetricalstr(a))
    {
        cout << "Yes";
    }else{
        cout << " No";
    }


}