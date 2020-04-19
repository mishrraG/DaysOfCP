package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int number = Integer.parseInt(br.readLine());
            int count = 0;
            int divider = 5;

            while ((number / divider) > 0) {
                count += number / divider;
                divider = divider * 5;
            }
            System.out.println(count);
        }
    }
}