import java.io.*;
class Buses {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
        int T=Integer.parseInt(br.readLine());
        int a=1;
        while(T-- != 0)
        {
            int c=0;
            String s[]=br.readLine().split(" ");
            int N=Integer.parseInt(s[0]);
            long D=Long.parseLong(s[1]);
            s=br.readLine().split(" ");
            for(int i=N-1;i>=0;--i) {

                D-=D%(Long.parseLong(s[i]));
            }
            bw.write("Case #"+a+": "+D+"\n");
            bw.flush();
            a++;
        }
    }
}