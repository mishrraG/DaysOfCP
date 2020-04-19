package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class TEST {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean flag =true;
        do {
            int x=Integer.parseInt(br.readLine());
            if(x==42)
                flag=false;
            else
                System.out.println(x);
        }while (flag==true);
    }
}
