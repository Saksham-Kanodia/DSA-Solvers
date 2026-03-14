import java.util.Scanner;

public class tableOfNumber {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a number: ");
        int num = scanner.nextInt();

        System.out.println("The table is: ");
        for(int i=1; i<=10; i++){
            System.out.println(num*i);
        }

        scanner.close();
    }
}
