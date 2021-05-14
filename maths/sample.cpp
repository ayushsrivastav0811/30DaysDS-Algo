#include<bits/stdc++.h>

#define ll     long long
#define rep(i,x,y)     for(i=x;i<y;i++)
#define  f               first
#define s              second
#define pb             push_back
using namespace std;
//GCD of two number using Euclidean Algorithm
//Time Complexity=O(log(min(a,b))
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
//a*b=gcd(a,b)*lcm(a,b)
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
bool isprime(int n){
	if(n==1)
	return 0;
	if(n==2||n==3)
	return 1;
	if(n%2==0 || n%3==0)
	return 0;
	for(ll i=5;i*i<=n;i+=6){
		if(n%i==0 || n%(i+2)==0)
		    return 0;
		return 1;
	}
}
ll divisors(ll n){
	ll i;
	rep(i,1,sqrt(n))
	{  
	if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
            cout<<i<<" ";
 
            else // Otherwise print both
            cout<<i<<" "<<n/i<<" ";
        }
    
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j,c=0,x=1,y=1,a,b,d,n,t;
    string str,str1,str2,s1,s2;
    cin>>t;
    while(t--)
    {
    	cin>>n;
		divisors(n);
	}
}


