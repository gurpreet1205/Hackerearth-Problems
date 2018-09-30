#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,i,j,k,ans,x,z=100000;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		long long int a[n],count[100001]={0};
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			count[a[i]]++;
		}
		sort(a,a+n);
		for(i=1;i<100001;i++)
		{
			count[i]=count[i-1]+count[i];
		}
		for(i=0;i<n;i++)
		{
			ans=ans+count[min(z,a[i]*2)]-count[a[i]-1];
		}
		for(i=0;i<n;i++)
		{
			k=1;
			x=a[i]/2-1+a[i]%2;
			for(j=a[i];j<=a[n-1];j=j+a[i])
			{
				ans=ans+(count[min(a[n-1],j+x)]-count[j])*k;
				k++;
				ans=ans+(count[min(a[n-1],j+a[i])]-count[min(a[n-1],j+x)])*k;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}