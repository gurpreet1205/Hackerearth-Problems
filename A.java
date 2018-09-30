/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.util.*;
class A {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        */

        // Write your code here
        int i,j,k,u,v;
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        Node arr[]=new Node[n+1];
        for(i=1;i<n+1;i++){
            arr[i]=new Node(i);
        }
        for(i=0;i<n-1;i++)
        {
            //u=s.nextInt();
            //v=s.nextInt();
            u=i+1;
            v=i+2;
            arr[u].list.add(arr[v]);
            arr[v].list.add(arr[u]);
        }
        calculate(arr[1],1);
        for(i=1;i<=n;i++)
            System.out.print(arr[i].Y+" ");
    }
    public static int calculate(Node node,int Z){
        if((node.list.size()==1&&node.index!=1)||(node.index==1&&node.list.size()==0)){
           node.X=0;
           node.Y=0;
           return 0;
        }
        int x,y=0,z=0,m=-1;
        for(int i=0;i<node.list.size();i++){
            //System.out.println(node.index+" "+node.list.get(i).index);
            if(node.list.get(i).index==Z)
                continue;
            x=calculate(node.list.get(i),node.index);
            //System.out.println(x+" "+node.index+" "+node.list.get(i).index);
            if(x>y){
                y=x;
            }
            if(node.X<=node.list.get(i).X){
                node.X=node.list.get(i).X+1;
                z=i;
            }
        }
        for(int i=0;i<node.list.size();i++){
            if(i==z||node.list.get(i).index==Z){
                continue;
            }
            if(m<node.list.get(i).X){
                m=node.list.get(i).X;
            }
        }
        m=m+1;
        if(node.X+m>y){
            node.Y=node.X+m;
            return node.Y;
        }
        node.Y=y;
        return y;
    }
}
class Node{
    public ArrayList<Node> list=new ArrayList<Node>();
    public int X,Y,index;
    Node(int i){
        index=i;
        X=0;
        Y=0;
    }
}
