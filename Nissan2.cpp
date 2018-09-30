#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,i,j,m=0,s=0;
	cin>>n>>k;
	long long int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<k;i++)
	{
		s=s+a[i];
		m=s;
	}
	for(i=n-1,j=1;i>n-k;i--)
	{
		s=s+a[i]-a[k-j];
		m=max(m,s);
		j++;
	}
	cout<<m<<"\n";
	return 0;
}