import java.util.Scanner;

public class EMPLOYEE {

    String Ename;
    String Eid;
    double basic, DA, Gross_Sal,Net_Sal;

    EMPLOYEE(){
        Ename = "Saksham Kanodia";
        Eid="101";
        basic= 13000.00;
    }

    EMPLOYEE(String name, String id, double salary){
        Ename = name;
        Eid = id;
        basic = salary;
    }

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

        //using default constructor
        EMPLOYEE e1 = new EMPLOYEE();
        e1.compute_net_sal();
        e1.display();
        System.out.println();

        //using parameterized constructor
        EMPLOYEE e2 = new EMPLOYEE("Saksham Kanodia", "102", 14000);
        e2.compute_net_sal();
        e2.display();
        System.out.println();

        //using assign method
        EMPLOYEE e3 = new EMPLOYEE();
        e3.assign(scanner);
        e3.compute_net_sal();
        e3.display();
        System.out.println();

        scanner.close();
    }
}
