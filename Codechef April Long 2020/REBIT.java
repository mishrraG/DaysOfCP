//Question Link : https://www.codechef.com/APRIL20B/problems/REBIT
import java.util.*;
class Operand {
    long c0 = 1, c1 = 1, ca = 1;
    public long countAll() {
        return c0 + c1 + ca * 2;
    }
    public long a() { return ca; }
    public long A() { return ca; }
}

class REBIT {


    static Operand eval(Operand op1, Operand op2, char operator) {

        Operand result = new Operand();
        if(operator=='&') {
            result.c1 = op1.c1 * op2.c1;

            result.c0 = op1.c0 * op2.countAll() % 998244353 + op1.countAll() * op2.c0 % 998244353 - (op1.c0 * op2.c0) + op1.a() * op2.A() * 2 % 998244353;

            result.ca = op1.a() * op2.a() % 998244353 + op1.a() * op2.c1 % 998244353 + op1.c1 * op2.a();
        }


        if(operator=='|') {
            result.c1 = op1.c1 * op2.countAll() % 998244353 + op1.countAll() * op2.c1 % 998244353 - (op1.c1 * op2.c1) + op1.a() * op2.A() * 2 % 998244353;

            result.c0 = op1.c0 * op2.c0;

            result.ca = op1.a() * op2.a() % 998244353 + op1.a() * op2.c0 % 998244353 + op1.c0 * op2.a();
        }
        if(operator=='^') {
                result.c0 = op1.c0 * op2.c0 % 998244353 + op1.c1 * op2.c1 % 998244353 + op1.a() * op2.a() * 2 % 998244353;

                result.c1 = op1.c0 * op2.c1 % 998244353 + op1.c1 * op2.c0 % 998244353 + op1.a() * op2.A() * 2 % 998244353;

                result.ca = op1.c1 * op2.A() % 998244353 + op1.A() * op2.c1 % 998244353 + op1.a() * op2.c0 % 998244353 + op1.c0 * op2.a() % 998244353;
        }

        result.c0 %= 998244353;
        result.c1 %= 998244353;
        result.ca %= 998244353;
        return result;
    }

    static Operand solve(String s , Stack<Object> stack) {


        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(ch == '#')
                stack.push(new Operand());
            else if(ch != ')')
                stack.push(ch);

            else {	// closing bracket, time to evaluate the last expression
                Operand op1 = (Operand) stack.pop();
                char operator = (char) stack.pop();
                Operand op2 = (Operand) stack.pop();
                stack.pop();	// removing ( bracket
                Operand result = eval(op1, op2, operator);
                stack.push(result);
            }
        }
        return (Operand) stack.pop();
    }

    static long power(int p,long a) {

        if(p == 0)
            return 1;
        long ans = power(p/2,a);
        ans =ans * ans % 998244353;
        if((p & 1) == 1)
            ans = ans * a % 998244353;
        return ans;
    }


    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            String exp = sc.next();
            Stack<Object> stack = new Stack();
            Operand ans = solve(exp,stack);

            long Q = power(998244353-2,ans.countAll());
            ans.c0=ans.c0 * Q % 998244353;
            if(ans.c0 <0)
                ans.c0+=998244353;
            ans.c1=ans.c1 * Q % 998244353;
            if(ans.c1 <0)
                ans.c1+=998244353;
            ans.ca=ans.ca * Q % 998244353;
            if(ans.ca <0)
                ans.ca+=998244353;
            System.out.println(ans.c0+" "+ans.c1+" "+ans.a()+" "+ans.A());
        }
    }

}
