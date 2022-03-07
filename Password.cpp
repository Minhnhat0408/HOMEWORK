#include <iostream>
#include <algorithm>
#include<iomanip>
#include<string>
using namespace std;


int main()
{	
    int n;
    cin >> n;
    string pass[n],answer;
    bool found = false;
    for(int i =0 ;i < n;i++)
    {
        cin >> pass[i];
    }
    for(int i =0 ; i < n;i++)
    {   
        reverse(pass[i].begin(),pass[i].end());
        for(int j = i+1;j < n;j++)
        {
            if(pass[i] == pass[j])
            {
                answer = pass[i];
                found = true;
                break;
            }
        }
        if(found) break;
    }
    cout << answer.size() << " " << answer[(int) answer.size()/2] ;
}