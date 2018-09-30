/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i,j,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=n-1;
        z=0;
        j=0;
        while(x!=0)
        {
            y=x%2;
            x=x/2;
            z=z+y*pow(2,j);
            j++;
        }
        cout<<(long long int)pow(2,j)-1<<" ";
        x=floor(log(n-1)/log(2));
        if(n==1)
        cout<<1<<"\n";
        else
            cout<<(long long int)((n-1-(long long int)pow(2,x)+1)*2)<<"\n";
    }
    return 0;
}