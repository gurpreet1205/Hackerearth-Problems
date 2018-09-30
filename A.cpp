#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,i,j,x,p;
	cin>>n>>k;
	long long int a[n],o[n],e[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	if(k%2!=0&&n==1)
		cout<<-1<<"\n";
	else
	{
		x=min(n,k+1);
		j=0;
		p=0;
		for(i=0;i<x;i++)
		{
			if(i!=x-2)
				o[i]=a[i];
		}
		sort(o,o+(x-1));
		cout<<o[x-2];
	}
	return 0;
}