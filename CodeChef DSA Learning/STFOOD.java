import java.io.*;

class STFOOD {
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t=Integer.parseInt(br.readLine());

        while (t-->0) {
            int n = Integer.parseInt(br.readLine());
            long m=0;
            while (n-- > 0) {
                String str[] = br.readLine().split(" ");
                long s = Long.parseLong(str[0]);
                long p = Long.parseLong(str[1]);
                long v = Long.parseLong(str[2]);
                long val = (p / (s + 1))*v;
                m = Math.max(m,val);
            }
            bw.write(m+"\n");
            bw.flush();
        }
        bw.close();
        br.close();
    }
}
