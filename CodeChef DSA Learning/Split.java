package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Split {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String args[]) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve();
        }
    }

    static void solve() throws IOException {
        String one, two;
        String s = br.readLine();
        int freq1[] = new int[26];
        int freq2[] = new int[26];
        Arrays.fill(freq1, 0);
        Arrays.fill(freq2, 0);
        if (s.length() % 2 == 0) {
            one = s.substring(0, s.length() / 2);
            two = s.substring(s.length() / 2);
        } else {
            one = s.substring(0, s.length() / 2 + 1);
            two = s.substring(s.length() / 2);
        }
        for (int i = 0; i < one.length(); i++) {
            freq1[one.charAt(i) - 'a']++;
        }
        for (int i = 0; i < two.length(); i++) {
            freq2[two.charAt(i) - 'a']++;
        }
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i])
                c++;
        }
        if (c == 26)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
