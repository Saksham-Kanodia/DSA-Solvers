import java.util.Scanner;

public class taxiService {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the distance travelled:");
        double d = scanner.nextDouble();

        double fare =0;
        if(d<=5){
            fare += d*10;
            System.out.println("The fare will be: " +fare);
        }
        else if(d <= 20) {
            fare += 5*10 + (d-5)*8;
            System.out.println("The fare will be: " +fare);
        }
        else if (d<=45) {
            fare += 5*10 + 15*8 + (d-20)*5;
            System.out.println("The fare will be: " +fare);
        }
        else System.out.println("Travel services over 45 km. aren't offered.");

        scanner.close();
    }
}
