#include<bits/stdc++.h>
using namespace std;
long long int modifiedBinarySearch(double *a,long long int n,double x)
{
	long long int low=0,high=n-1,mid;
	if(a[0]>=x)
		return 0;
	if(a[n-1]<x)
		return n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>=x)
		{
			if(a[mid-1]<x)
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
	long long int t,n,i,j,k,q,x;
	cin>>n;
	long long int a[n];
	double b[n],s=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		s=s+a[i];
		b[i]=s/(i+1);
	}
	sort(b,b+n);
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>k;
		x=modifiedBinarySearch(b,n,(double)k);
		cout<<x<<"\n";
	}
	return 0;
}