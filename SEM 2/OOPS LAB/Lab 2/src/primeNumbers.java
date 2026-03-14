
import java.util.Scanner;

public class primeNumbers {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Program to print prime numbers between n and m");

        System.out.println("Enter n:");
        int n= scanner.nextInt();

        System.out.println("Enter m:");
        int m= scanner.nextInt();

        System.out.println("The prime numbers are: ");
        for(int i=n; i<=m; i++){
            boolean isPrime = true;
            for(int j=2; j*j<=i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) System.out.println(i);
        }

        scanner.close();
    }
}
