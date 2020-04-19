import java.util.*;
import java.lang.*;
import java.io.*;
class CARVANS
{
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        public FastReader()
        {
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreElements())
            {
                try{
                    st=new StringTokenizer(br.readLine());
                }
                catch(IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();}
        int nextInt()
        {
            return Integer.parseInt(next());
        }
    }
    public static void main (String[] args)
    {
        FastReader f=new FastReader();
        int K=f.nextInt();
        while(K-- > 0)
        {
            int n=f.nextInt();
            Queue<Integer> q=new LinkedList<Integer>();
            int count=0;
            for(int i=0;i<n;i++)
            {
                int a=f.nextInt();
                if(q.isEmpty())
                {
                    q.add(a);
                    count++;
                }
                if(a<q.peek())
                {
                    count++;
                    q.poll();
                    q.add(a);
                }
            }
            System.out.println(count);
        }
    }
}
