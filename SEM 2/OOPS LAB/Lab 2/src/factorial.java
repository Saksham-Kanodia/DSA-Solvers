import java.util.Scanner;

public class factorial {
    public static long fact(int n){
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a number: ");
        int num = scanner.nextInt();

        long fact = fact(num);
        System.out.println("The factorial of "+ num +" will be: " + fact);

        scanner.close();
    }
}
