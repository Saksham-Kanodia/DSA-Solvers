import java.util.Scanner;

public class joiningYear {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter registration no.:");
        String regNo = scanner.nextLine();

        String yearOfJoining = regNo.substring(0,2);
        System.out.println("The year of joining is 20" + yearOfJoining);

        scanner.close();
    }
}
