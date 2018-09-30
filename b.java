import java.io.*;
import java.util.*;
class b
{
	public static void main(String args[])throws IOException
	{
		int t,i,j,k,n,m,min=0;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		String[] s = new String[n];
		for(i=0;i<n;i++){
			s[i]=sc.next();
		}
		for(i=1;i<n;i++){
			if(s[min].compareTo(s[i])<0){
				min=i;
			}
		}
		System.out.println(min+1);
	}
}