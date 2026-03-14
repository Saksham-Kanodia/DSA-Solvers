import java.util.Scanner;

public class electricityBill {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the no. of units: ");
        int units = scanner.nextInt();

        double bill=0;
        int choice;

        if(units<=100) choice =1;
        else if (units<=200) choice=2;
        else choice=3;

        switch(choice){
            case 1:
                bill += units*7;
            case 2:
                bill += units*8;
            case 3:
                bill += units*10;
        }

        System.out.println("The electricity bill is: " + bill);

        scanner.close();
    }
}
