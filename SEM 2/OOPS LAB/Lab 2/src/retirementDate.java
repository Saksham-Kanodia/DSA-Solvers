import java.util.Scanner;

public class retirementDate {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter DOB (dd mm yyyy): ");
        String dob = scanner.nextLine();

        String retirementDate = dob.substring(0,6);
        String joiningYear = dob.substring(6,10);

        int retirementYear = Integer.parseInt(joiningYear) + 60;
        System.out.print("The retirement date will be: " + retirementDate + retirementYear);

        scanner.close();
    }
}
