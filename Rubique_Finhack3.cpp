#include<bits/stdc++.h>
using namespace std;
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
	long long int n,i,j,k,x,c=0,d=0,y,z,p=1000000007,q[26]={0},r[26]={0};
	char ch;
	cin>>n;
	long long int a[26][26];
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
			a[i][j]=0;
	}
	for(i=0;i<26;i++)
	{
		cin>>x;
		for(j=0;j<x;j++)
		{
			cin>>ch;
			a[i][ch-'a']=1;
		}
	}
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			if(i!=j&&a[i][j]==1&&a[j][i]==1)
				c++;
		}
	}
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			if(a[i][j]==1&&a[j][i]==1)
				q[i]++;
		}
	}
	for(i=0;i<26;i++)
	{
		if(a[i][i]==1)
			d++;
	}
	if(c==0)
		cout<<"0\n";
	else
	{
		if(n%4==0)
		{
			y=power(c+d,n/4,p);
			cout<<y<<"\n";
		}
		else if(n%2==0)
		{
			y=power(c+d,(n-2)/4,p);
			y=(y*d)%p;
			cout<<y<<"\n";
		}
		else
		{
			n=n-5;
			if(n%4==0)
			{
				y=power(c+d,n/4+1,p);
				cout<<y<<"\n";
			}
			else if(n%2==0)
			{
				y=power(c+d,(n-2)/4+1,p);
				y=(y*d)%p;
				cout<<y<<"\n";
			}
		}
	}
	return 0;
}