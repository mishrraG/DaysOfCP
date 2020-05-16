import java.io.*;

class Solution {
    public static String conv(String s){
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(')
                ctr++;
        }
        while (ctr-->0) {
            String left;
            String right;
            String brack;
            left = s.substring(0, s.lastIndexOf('(') - 1);
            right = s.substring(s.indexOf(')', s.lastIndexOf('(')) + 1);
            brack = s.substring(s.lastIndexOf('(') - 1, s.indexOf(')', s.lastIndexOf('(')) + 1);
            int c = Integer.parseInt(String.valueOf(brack.charAt(0)));
            brack = brack.substring(2, brack.length() - 1);
            s = left;
            while (c-- > 0)
                s = s + brack;
            s = s + right;
        }
        return s;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        int c=1;
        while(c<=t){
            String s = br.readLine();
            long x=1;
            long y=1;
            s=conv(s);
            for(int i=0;i<s.length();i++)
            {
                char ch=s.charAt(i);
                if(ch=='S')
                    y++;
                else if(ch=='N')
                    y--;
                else if(ch=='W')
                    x--;
                else if(ch=='E')
                    x++;
            }
            long max = 1000000000;
            if(x<=0) {
                x%=max;
                x+=max;
            }
            if(y<=0) {
                y%=max;
                y+=max;
            }
            bw.write("Case #"+c+": "+x+" "+y+"\n");
            bw.flush();
            c++;
        }

    }
}
