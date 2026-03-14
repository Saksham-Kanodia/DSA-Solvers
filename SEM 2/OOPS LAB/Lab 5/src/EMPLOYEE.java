import java.util.Scanner;

public class EMPLOYEE {
    String EmployeeName;
    double EmployeeSalary;
    Department[] d;
    int n;
    int count=0;

    EMPLOYEE(String EmployeeName, double EmployeeSalary, int n){
        this.EmployeeName = EmployeeName;
        this.EmployeeSalary = EmployeeSalary;
        this.n = n;
        d = new Department[n];
    }

    class Department{

        String DepartmentName;
        String location;

        void assign(Scanner scanner){
            System.out.println("Enter your Department Name: ");
            DepartmentName = scanner.nextLine();

            System.out.println("Enter your Location: ");
            location = scanner.nextLine();
        }

        void displayDepartmentDetails(){
            System.out.println("Department Name: " + DepartmentName);
            System.out.println("Department Location: " + location);
        }

    }

    void addDepartments(Scanner scanner){
        d[count] = new Department();
        d[count].assign(scanner);
        count++;
    }

    void display(){
        System.out.println("Employee Name: " + EmployeeName);
        System.out.println("Employee Salary: " + EmployeeSalary);
        for(int i=0; i<n; i++){
            d[i].displayDepartmentDetails();
            System.out.println();
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Employee name: ");
        String name = scanner.nextLine();

        System.out.println("Enter salary: ");
        double salary = scanner.nextDouble();
        scanner.nextLine();

        System.out.println("Enter no. of departments: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        EMPLOYEE employee = new EMPLOYEE(name,salary,n);

        for(int i=0; i<n; i++){
            employee.addDepartments(scanner);
        }

        employee.display();

        scanner.close();
    }

}
