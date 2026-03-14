import java.util.Scanner;

public class palindrome {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a number: ");
        int num = scanner.nextInt();
        int org=num;
        int rev=0;
        while(num>0){
            int rem = num%10;
            rev = rev*10 + rem;
            num/=10;
        }
        if(rev==org) System.out.println("Yes, Palindrome");
        else System.out.println("No, not Palindrome");

        scanner.close();
    }
}
