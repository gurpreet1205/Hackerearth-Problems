#include<bits/stdc++.h>
using namespace std;
long long int prime[1000001]={0};
long long int arr[1001][1001]={0},p=1000000007;
long long int nCr(long long int n,long long int r,long long int p)
{
	if(arr[n][r]!=0)
		return arr[n][r];
	if(n==r||r==0)
	{
		arr[n][r]=1;
		return 1;
	}
	if(r==1)
	{
		arr[n][r]=n;
		return n;
	}
	if(n<r)
		return 0;
	arr[n][r]=(nCr(n-1,r-1,p)+nCr(n-1,r,p))%p;
	return arr[n][r]%p;
}
void sieve()
{
	prime[1]=1;
	long long int i,j;
	for(i=2;i<1000;i++)
	{
		if(prime[i]==0)
		{
			for(j=i*2;j<1000001;j=j+i)
			{
				prime[j]=1;
			}
		}
	}
}
long long int power(long long int a,long long int b,long long int p)
{
	if(b==0)
		return 1;
	if(b%2==0)
		return (power((a*a)%p,b/2,p))%p;
	else
		return (a*power((a*a)%p,(b-1)/2,p))%p;
}
int main()
{
	long long int t,n,i,j,k,pr,c,ans,subsets,x;
	sieve();
	cin>>t;
	while(t--)
	{
		c=0,pr=0;
		cin>>n;
		long long int a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			if(prime[a[i]]==0)
				pr++;
			else
				c++;
		}
		subsets=power(2,c,p-1);
		ans=power(2,subsets,p);
		for(i=1;i<=pr;i++)
		{
			x=nCr(pr,i,p-1);
			ans=(ans*power(i+2,subsets*x,p))%p;
		}
		cout<<ans<<"\n";
	}
	return 0;
}