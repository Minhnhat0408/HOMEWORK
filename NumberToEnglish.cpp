#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
using namespace std;

int main()
{	
	string lib[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
     "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};
    int x,i = 0;
    cin >> x;
    int n= x;
    vector <int> a;
    string ans;
    while(abs(x)!=0)
    {
        a.push_back(abs(x)%10);
        x =abs(x)/10;
        i++;
        
    }
    if(i <2)
    {
        ans = lib[abs(n)];
    }else{
        if(a[0]+a[1]*10 <=20 )
        {
            ans = lib[a[0]+a[1]*10];
        }else{
            a[1] = 20+ a[1]-2;
            ans = lib[a[1]] +" "+ lib[a[0]];
        }
    }
    if(i >2 && a[2] !=0){
        ans = lib[a[2]] +" "+ lib[28]+" "+ ans;
    }else{
        ans = "and " +ans;
    }
    if(i >3)
    {
        ans = lib[29]+" " +ans;
        if(i <5)
        {
            ans = lib[a[3]] + " "+ ans;
        }else{
            if(a[3]+a[4]*10 <=20 )
            {
                ans = lib[a[3]+a[4]*10]+" "+ans;
            }else{
                a[4] = 20+ a[4]-2;
                ans = lib[a[4]] +" "+ lib[a[3]]+" "+ ans;
            }
            if(i >5 && a[5] !=0) ans = lib[a[5]] +" "+ lib[28]+" "+ ans;

        }
    }
    if(i >6)
    {
        ans = lib[30]+ " " + ans;
        if(i <8)
        {
            ans = lib[a[6]]+ " "+ ans;
        }else{
            if(a[6]+a[7]*10 <=20 )
            {
                ans = lib[a[6]+a[7]*10] + " " +ans;
            }else{
                a[7] = 20+ a[7]-2;
                ans = lib[a[7]] +" "+ lib[a[6]] + " " +ans;
            }
            if(i>8) ans = lib[a[8]] +" "+ lib[28]+" "+ ans;
        }
        
    }
    if(i > 1)
    {
        for(int j = 0;j < ans.size();j++)
        {
            if(ans[j] == 'z') ans.erase(j,4);
        }
    }
    if(n < 0)
    {
        ans = "negative " +ans;
    }
    cout << ans;
 
} 