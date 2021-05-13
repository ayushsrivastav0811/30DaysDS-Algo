#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
int i,n;
cin>>n;
for(i=1;i<=10;i++)
{
	cout<<n*i;
	if(i<10)
	cout<<" -> ";
}
    return 0;
}
