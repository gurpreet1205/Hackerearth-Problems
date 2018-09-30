#include<bits/stdc++.h>
using namespace std;
long long int modifiedBinarySearch(long long int *a,long long int n,long long int x)
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
    long long int i,j,q,n,s=0,y,x;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    j=0;
    long long int b[a[n-1]+1];
    b[0]=0;
    for(i=1;i<=a[n-1];i++)
    {
        while(a[j]<i)
            s=s+a[j++];
        cout<<i<<" "<<j<<" "<<s<<"\n";
        b[i]=(n-j)*i+s;
    }
    for(i=0;i<=a[n-1];i++)
        cout<<b[i]<<" ";
    cout<<"\n";
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x;
        y=modifiedBinarySearch(b,a[n-1]+1,x);
        if(y==a[n-1]+1)
            cout<<"-1\n";
        else
            cout<<y<<"\n";
    }
    return 0;
}