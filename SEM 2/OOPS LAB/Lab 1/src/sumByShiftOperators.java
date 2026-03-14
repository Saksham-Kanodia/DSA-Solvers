import java.util.Scanner;

public class sumByShiftOperators {
    public static void main(String[] args){
        //program to calculate sum of two numbers using shift operators
        Scanner scanner = new Scanner(System.in);

        //declaration
        int num1,num2;

        //user input
        System.out.println("Enter number 1: ");
        num1=scanner.nextInt();

        System.out.println("Enter number 2: ");
        num2=scanner.nextInt();

        //calculating sum
        while(num2!=0){
            int carry = num1 & num2;
            num1 = num1 ^ num2;
            num2 = carry << 1;
        }

        //output
        System.out.println("The sum is " + num1);

        if((num1 & 1)==0) System.out.println("The number is even.");
        else System.out.println("The number is odd.");
    }
}
