#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	for(int i=2;i<=n;i++)
	if(n%i==0)
	return 0;
	return 1;
}
int main()
{
	int i,n;
	cin>>n;
	for(int i=2;i<=n;i++)
	if(isprime(i))
	cout<<i<<" ";
	
	
}
