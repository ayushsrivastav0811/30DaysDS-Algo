/*********************************************************************
            Name:Ayush Srivastav
**********************************************************************/
#include<bits/stdc++.h>
#define ll              long long
#define rep(i,x,y)      for(i=x;i<y;i++)
#define  f              first
#define s               second
#define pb              push_back
using namespace std;

ll                      i,j,c=0,x=1,y=1,r=0,result=0,ans=1,temp=0,sum=1,a,b,d,n,m,t;
string                  str,str1,str2,s1,s2,s3=" ";

//GCD of two number using Euclidean Algorithm
//Time Complexity=O(log(min(a,b))

ll gcd(ll a,ll b) {
    if(b==0)
    return a;
	else
	return gcd(b,a%b);
}

//a*b=gcd(a,b)*lcm(a,b)
//Fastest Way of Finding LCM

ll lcm(ll a,ll b){

	return a*b/gcd(a,b);
}

//This is also funtion of finding prime numbers but time complexity
//is more.
//Time Complixity: O(n^3/2)

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
//Sieve of Eratosthenes
//it will print all the prime numbers
//Time Complexity :O(log log n)
void sieve (int n)
{
	vector<bool>isprime(n+1,true );
	{
		for(i=2;i<=n;i++)
		{
			if(isprime[i])
			{
				cout<<i<<" ";
				for(j=i*i;j<=n;j+=i)
				{
					isprime[j]=false;
				}
			}
		}

	}
}
int power(ll n,ll m)
{

	for(i=0;i<m;i++)
	{
		sum=sum*n;
	}
	cout<<sum;
}
//calculating the Power of the number using itreative
//Time Complexity O(log n)
//Space Complexity O(1)
ll powe(ll n, ll m) {
	while(m>0)
  {
    if(m&1)
    ans*=n;
    n*=n;
    m=m>>1;
  }
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    cin>>t;
t=1;
    while(t--)
    {
    	cin>>n;
      int arr[n];
      for(i=0;i<n;i++)
      {
      	cin>>arr[i];
	  }
	  for(i=0;i<n;i++)
	  {
	  	c=0;
	  	for(j=0;j<n;j++)
	  	{
	  		if(arr[j]==arr[i])
	  		c++;
		  }
		  if(c%2!=0)
		  cout<<arr[i]<<" ";
	  }

	}
	return 0;
}




