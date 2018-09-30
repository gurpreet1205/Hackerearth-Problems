#include<bits/stdc++.h>
using namespace std;
long long int ans[1001][1001],l[1001][1001],r[1001][1001],n,m;
long long int calculate(long long int i,long long int j)
{
	if(i==n-1)
		return 1;
	if(ans[i][j]!=0)
		return ans[i][j];
	long long int x=0,k;
	for(k=l[i][j]-1;k<r[i][j];k++)
	{
		x=(x+calculate(i+1,k))%1000000007;
	}
	ans[i][j]=x;
	return ans[i][j];
}
int main()
{
	long long int i,j,k;
	cin>>n>>m;
	long long int a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			ans[i][j]=0;
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m;j++)
			cin>>l[i][j];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m;j++)
			cin>>r[i][j];
	}
	long long int sum=0;
	for(i=0;i<m;i++)
	{
		sum=(sum+calculate(0,i))%1000000007;
	}
	cout<<sum%1000000007<<"\n";
	return 0;
}