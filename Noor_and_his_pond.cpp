#include<bits/stdc++.h>
using namespace std;
void mergesort(long long int *a,long long int n,long long int *c,long long int *e)
{
    long long int b[n],d[n],g[n];
    long long int x;
    if((n==0)||(n==1))
        return;
    x=n/2;
    mergesort(a,x,c,e);
    mergesort(a+x,n-x,c+x,e+x);
   long long int i=0,j=x,k=0;
    while((i<x)&&(j<n))
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            d[k]=c[j];
            g[k]=e[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            d[k]=c[i];
            g[k]=e[i];
            i++;
        }
        k++;
    }
    if(i==x)
    {
        while(j<n)
        {
            b[k]=a[j];
            d[k]=c[j];
            g[k]=e[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<x)
        {
            b[k]=a[i];
            d[k]=c[i];
            g[k]=e[i];
            i++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
        c[i]=d[i];
        e[i]=g[i];
    }
}

long long int modifiedBinarySearch(long long int *a,long long int n,long long int x)
{
	long long int low=0,high=n-1,mid;
	if(a[0]>x)
		return 0;
	if(a[n-1]<=x)
		return n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>x)
		{
			if(a[mid-1]<=x)
				return mid;
			else
				high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
}

int main()
{
	long long int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int s[n],e[n],d[n]={0};
		for(i=0;i<n;i++)
		{
			cin>>s[i]>>e[i];
		}
		mergesort(s,n,e,d);
		long long int a[n],b[n+1]={0},c[n];
		a[0]=0;
		for(i=1;i<n;i++)
		{
			a[i]=modifiedBinarySearch(s,n,e[i]);
		}
		for(i=0;i<n;i++)
		{
			b[a[i]]++;
		}
		for(i=n-1;i>0;i--)
		{
			b[i]=b[i+1]+b[i];
		}
		for(i=0;i<n;i++)
			c[i]=a[i]+b[i-1];
		mergesort(c,n,s,e);
		long long int ans=1,y=s[0],z=e[0];
		for(i=1;i<n;i++)
		{
			if(e[i]>=y||z>=s[i])
				continue;
			ans++;
			y=min(y,s[i]);
			z=max(z,e[i]);
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}