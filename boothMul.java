import java.util.Scanner;

public class boothMul {
    static String binaryString (int n)
    {
        StringBuilder ans = new StringBuilder();
        if(n > 0){
            ans.append("0");
            ans.append(Integer.toBinaryString(n));
            return ans.toString();
        }
        int temp = (int)(Math.log(-1 * n)/Math.log(2))+1;
        String str = Integer.toBinaryString(n);
        int i = 0;
        while(temp + 1 != 0 ){
            ans.append(str.charAt(str.length()-1-i));
            i++;
            temp--;
        }
        return ans.reverse().toString();
    }
    static String lengthMatch (String s, int n,int diff)
    {
        StringBuilder ans = new StringBuilder();
        if(n>0){
            while(diff > 0){
                ans.append("0");
                diff--;
            }
        }
        else{
            while(diff > 0){
                ans.append("1");
                diff--;
            }
        }
        return ans.append(s).toString();

    }
    static String binaryAdd (String a, String b)
    {
        int carry = 0;
        StringBuilder ans = new StringBuilder();
        for(int i = a.length()-1; i >= 0; i--){
            if(carry == 0){
                if(a.charAt(i) == '1' && b.charAt(i) == '0' || a.charAt(i) == '0' && b.charAt(i) == '1'){
                    ans.append("1");
                }
                else if(a.charAt(i) == '0' && b.charAt(i) == '0'){
                    ans.append("0");
                }
                else{
                    ans.append("0");
                    carry = 1;
                }
            }
            else{
                if(a.charAt(i) == '0' && b.charAt(i) == '0'){
                    ans.append("1");
                    carry = 0;
                }
                else if(a.charAt(i) == '0' && b.charAt(i) == '1' || a.charAt(i) == '1' && b.charAt(i) == '0'){
                    ans.append("0");
                }
                else{
                    ans.append("1");
                }
            }

        }
        return ans.reverse().toString();
    }
    static String negateNum(String s)
    {
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '0') {
                ans.append('1');
            }
            else {
                ans.append('0');
            }
        }
        String str = "0".repeat(ans.length()-1) + "1";
        return binaryAdd(ans.toString(),str);
    }
    static int binaryToDecimal(String s)
    {
        int ans = 0;
        int count = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s.charAt(i) == '1'){
                ans += (int)Math.pow(2,count);
            }
            count++;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1,n2;
        System.out.println("\nFor Multiplication (n1*n2)");
        System.out.print("\nEnter the number (n1): ");
        n1 = sc.nextInt();
        System.out.print("Enter the number (n2): ");
        n2 = sc.nextInt();
        String s1 = binaryString(n1);
        String s2 = binaryString(n2);
        String negS1 = binaryString(-n1);
        if(s1.length() > s2.length()){
            s2 = lengthMatch(s2,n2,s1.length() - s2.length());
        }
        else{
            s1 = lengthMatch(s1,n1,s2.length() - s1.length());
        }
        if(negS1.length() != s1.length()){
            negS1 = lengthMatch(negS1,-n1,Math.abs(s1.length()-negS1.length()));
        }
        System.out.println("\nData");
        System.out.println(n1 + ": " + s1);
        System.out.println(n2 + ": " + s2);
        System.out.println(-n1 + ": " + negS1);

        System.out.println("\nIteration Below For Ans");

        int n = s1.length();
        int number = n;

        String A = "0".repeat(s1.length());
        String Q = s2;
        String Q1 = "0";
        int count = 1;
        while(number != 0){
            System.out.println("Iteration #"+count);

            if(Q.charAt(n-1) == Q1.charAt(0)){
                Q1 = Q.charAt(n-1) + "";
                String t = Q.substring(0,n-1);
                Q = A.charAt(n-1) + t;
                t = A.substring(0,n-1);
                A = A.charAt(0) + t;

                System.out.println("A:"+ A +"| Q:"+ Q + "| Q1:"+ Q1);

            }
            else if(Q.charAt(n-1) > Q1.charAt(0)){
                A = binaryAdd(A,negS1);
                Q1 = Q.charAt(n-1) + "";
                String t = Q.substring(0,n-1);
                Q = A.charAt(n-1) + t;
                t = A.substring(0,n-1);
                A = A.charAt(0) + t;

                System.out.println("A:"+ A +"| Q:"+ Q + "| Q1:"+ Q1);

            }
            else {
                A = binaryAdd(A,s1);
                Q1 = Q.charAt(n-1) + "";
                String t = Q.substring(0,n-1);
                Q = A.charAt(n-1) + t;
                t = A.substring(0,n-1);
                A = A.charAt(0) + t;

                System.out.println("A:"+ A +"| Q:"+ Q + "| Q1:"+ Q1);

            }
            number--;
            count++;
        }
        String finalAns = A + Q ;
        System.out.println("\nAns: "+finalAns);
        int signFlag = 0;
        if(finalAns.charAt(0) == '1'){
            finalAns = negateNum(finalAns);
            signFlag = 1;
        }
        int deciAns = binaryToDecimal(finalAns);
        if(signFlag == 1){
            deciAns = -deciAns;
        }

        System.out.println("Ans: " + deciAns);
        System.out.println("Check: " + n1 + "*" + n2 + " = " + (n1*n2));

    }
}
