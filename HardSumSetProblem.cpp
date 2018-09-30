#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int k,i,j=0,n,x=0;
	cin>>k;
	n=(k+1)/2;
	n=n>=50?n:50;
	long long int c,a[n],b[n];
	for(i=0;i<k;i++)
		cin>>c;
	if(k%2==0&&k>=100)
	{
		n=n+1;
		cout<<n<<"\n";
		for(i=0;i<n;i++)
			cout<<i+1<<" ";
		cout<<"\n"<<n<<"\n";
		for(i=0;i<n;i++)
			cout<<i+1<<" ";
	}
	else
	{
		cout<<n<<"\n";
		for(i=0;i<n;i++)
			cout<<i*2+1<<" ";
		cout<<"\n"<<n<<"\n";
		for(i=0;i<n;i++)
			cout<<i*2+1<<" ";
	}
	return 0;
}