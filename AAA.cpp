#include<bits/stdc++.h>
using namespace std;
long long int prime[1000001]={0},arr[1000000],k;
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
	k=0;
	for(i=1;i<1000001;i++)
	{
	    if(prime[i]==0)
	    {
	        arr[k++]=i;
	    }
	}
}
int main()
{
	sieve();
	long long int m=0,i;
	for(i=0;i<k-1;i++)
		m=max(m,arr[i+1]-arr[i]);
	cout<<m;
	return 0;
}