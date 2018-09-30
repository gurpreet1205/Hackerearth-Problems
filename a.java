import java.io.*;
import java.util.*;
class a
{
	public static void main(String args[])throws IOException
	{
		int t,n,i,j,k,q,l,r,o,e,x=0;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t-->0){
			n=sc.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			for(i=0;i<n;i++){
				a[i]=sc.nextInt();
			}
			for(i=0;i<n;i++){
				if(a[i]%2!=0&&a[i]!=1){
					if(i==0)
						b[i]=1;
					else
						b[i]=b[i-1]+1;
				}
				else{
					if(i==0)
						b[i]=0;
					else
						b[i]=b[i-1];
				}
			}
			q=sc.nextInt();
			for(i=0;i<q;i++){
				x=0;
				l=sc.nextInt();
				r=sc.nextInt();
				if(a[l-1]%2!=0&&a[l-1]!=1)
					x=1;
				o=b[r-1]-b[l-1]+x;
				e=r-l+1-o;
				if(e<o)
					System.out.println((o-e+1)/2);
				else
					System.out.println(0);
			}
		}
	}
}