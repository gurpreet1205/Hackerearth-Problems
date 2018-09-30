#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m,i,j,k,s;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	long long int c[m];
	for(i=0;i<m;i++)
		cin>>c[i];
	long long int b[100];
	for(i=1;i<=100;i++)
	{
		for(j=0;j<n;j++)
		{
			s=i+a[j];
			for(k=0;k<m;k++)
			{
				if(s==c[k])
					break;
			}
			if(k==m)
				break;
		}
		if(j==n)
			cout<<i<<" ";
	}
	return 0;
}