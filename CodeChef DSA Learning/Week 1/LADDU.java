package com.company;

import java.io.*;

class LADDU {
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        while (t-->0){
            boolean indian=false;
            String s[]=br.readLine().split(" ");
            int n=Integer.parseInt(s[0]);
            indian=(s[1].compareTo("INDIAN")==0);
            int checkout=200;
            if(!indian)
                checkout=400;
            int lcount=0;
             while (n-->0){
                 String str[]=br.readLine().split(" ");
                 if(str[0].equals("CONTEST_WON")){
                     int rank = Integer.parseInt(str[1]);
                     int bonus = 20-rank;
                     bonus= Math.max(bonus, 0);
                     lcount+=300+bonus;
                 }
                 else if(str[0].equals("TOP_CONTRIBUTOR")){
                     lcount+=300;
                 }
                 else if(str[0].equals("BUG_FOUND")){
                     int severity = Integer.parseInt(str[1]);
                     lcount+=severity;
                 }
                 else if(str[0].equals("CONTEST_HOSTED")){
                     lcount+=50;
                 }
             }
             bw.write(lcount/checkout+ "\n");
             bw.flush();
        }
        bw.close();
        br.close();
    }
}
