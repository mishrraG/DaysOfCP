//https://www.codechef.com/MAY20B/problems/CHANDF
import java.io.*;
class CHANDF {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] s = br.readLine().split(" ");
            long x = Long.parseLong(s[0]);
            long y = Long.parseLong(s[1]);
            long l = Long.parseLong(s[2]);
            long r = Long.parseLong(s[3]);
            long result = 0;
            long val = x | y;
            if (Math.min(x, y) == 0)
                bw.write(0 + "\n");
            else if (val <= r)
                bw.write(val + "\n");
            else
                bw.write((int)(Math.pow(2, (int) (Math.log(Math.max(x, y)) +1)) - 1) + "\n");
            bw.flush();
        }
    }
}