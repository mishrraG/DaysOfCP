package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FLOW007 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-->0){
            int x=Integer.parseInt(br.readLine());
            System.out.println(rev(x));
        }
    }
    static int rev(int x){
        int c=0;
        while (x!=0){
            int q=x%10;
            c=c*10+q;
            x/=10;
        }
        return c;
    }
}
