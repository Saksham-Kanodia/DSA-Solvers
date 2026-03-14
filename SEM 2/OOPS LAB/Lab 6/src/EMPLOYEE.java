import java.util.Scanner;

public class EMPLOYEE {
    String EmployeeName;
    String EmployeeId;

    EMPLOYEE(String EmployeeName,String EmployeeId){
        this.EmployeeName= EmployeeName;
        this.EmployeeId= EmployeeId;
    }

    String formatEmployeeName(){
        String modifiedName = "";
        String[] words = EmployeeName.split(" ");
        for(int i=0; i<words.length; i++){
            modifiedName = modifiedName + words[i].substring(0,1).toUpperCase() + words[i].substring(1).toLowerCase() + " ";
        }
        return modifiedName;
    }

    String generateEmail(){
        String email = "";
        String[] words = EmployeeName.split(" ");

        email += words[0].substring(0,1).toLowerCase() + words[words.length-1].substring(0).toLowerCase() + "@gmail.com";

        return email;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of employees: ");
        int n= scanner.nextInt();
        scanner.nextLine();

        EMPLOYEE[] employee = new EMPLOYEE[n];
        for(int i=0; i<n; i++){
            System.out.println("Enter Employee name");
            String name = scanner.nextLine();

            System.out.println("Enter Employee Id: ");
            String Id = scanner.nextLine();

            employee[i] = new EMPLOYEE(name, Id);
        }

        for(int i=0; i<n; i++){
            System.out.println("Formatted Employee Name: " + employee[i].formatEmployeeName());
            System.out.println("Email: "+ employee[i].generateEmail());
            System.out.println();
        }

    }
}
