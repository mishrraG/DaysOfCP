https://www.codechef.com/MAY20B/problems/CORUS
import java.lang.*;
import java.io.*;
class CORUS
{
    public static void main (String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t=Integer.parseInt(br.readLine());
        while(t-->0){
            String[] s =br.readLine().split(" ");
            int q=Integer.parseInt(s[1]);
            String str=br.readLine();
            int[] freq =new int[26];
            for(int i=0;i<str.length();i++)
                freq[str.charAt(i)-'a']++;
            int count=0;
            while(q-->0){
                count=0;
                int x=Integer.parseInt(br.readLine());
                for(int i =0;i<freq.length;i++)
                {
                    if(freq[i]>x)
                        count+=(freq[i]-x);
                }
                bw.write(count+"\n");
                bw.flush();
            }
        }
    }
}