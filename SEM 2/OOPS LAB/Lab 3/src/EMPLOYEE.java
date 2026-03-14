import java.util.Scanner;

public class EMPLOYEE {

    String Ename;
    String Eid;
    double basic, DA, Gross_Sal,Net_Sal;

    void assign(Scanner scanner) {
        System.out.println("Enter Employee name:");
        Ename = scanner.nextLine();

        System.out.println("Enter Employee id:");
        Eid = scanner.nextLine();

        System.out.println("Enter Basic Salary:");
        basic = scanner.nextDouble();
        scanner.nextLine();
    }

    void compute_net_sal(){
        DA = 0.52 * basic;
        Gross_Sal = basic + DA;
        double IT = 0.30 * Gross_Sal;
        Net_Sal = Gross_Sal - IT;
    }

    void display(){
        System.out.println("Employee name: " + Ename);
        System.out.println("Employee ID: " + Eid);
        System.out.println("Basic Salary: " + basic);
        System.out.println("DA: "+ DA);
        System.out.println("Gross Salary: "+ Gross_Sal);
        System.out.println("Net Salary: "+ Net_Sal);
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of employees: ");
        int N = scanner.nextInt();
        scanner.nextLine();

        EMPLOYEE[] emp = new EMPLOYEE[N];

        for(int i=0; i<N; i++){
            System.out.println("ENTER DETAILS OF EMPLOYEE " + (i+1));

            emp[i] = new EMPLOYEE();

            emp[i].assign(scanner);
            emp[i].compute_net_sal();
        }

        for(int i=0; i<N; i++){
            emp[i].display();
            System.out.println();
        }

        scanner.close();
    }
}