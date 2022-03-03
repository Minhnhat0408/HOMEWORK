#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	int n;
	cin >> n;
	int arr[n],t= 0;
	for(int i = 0 ;i < n;i++)
	{
		cin >> arr[i];
		t+= arr[i];
	}
	cout << "Mean: " << (double) t/n << "\n"; 
	cout << "Max: " << *max_element(arr,arr+n) << "\n";
	cout << "Min: " << *min_element(arr,arr+n);
} 
