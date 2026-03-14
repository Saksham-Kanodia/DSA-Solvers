import java.util.Scanner;

public class STUDENT {
    String sname;
    int n;
    int[] marks_array;
    int total=0;
    double avg;

    STUDENT(String sname, int n){
        this.sname = sname;
        this.n = n;
        marks_array = new int[n];
    }

    void assign(Scanner scanner){
        System.out.println("Enter marks of subjects: ");
        for(int i=0; i<n; i++){
            marks_array[i]=scanner.nextInt();
        }
        scanner.nextLine();
    }

    void compute(){
        for(int i=0; i<n; i++){
            total+=marks_array[i];
        }
        avg= (double)total/n;
    }

    void display(){
        System.out.println("The name of student is " + sname);
        System.out.println("The marks are :");
        for(int i=0; i<n; i++){
            System.out.println(marks_array[i]);
        }
        System.out.println("The total is " + total);
        System.out.println("The average is "+ avg);
    }

}

class ScienceStudent extends STUDENT{
    int practicalMarks;

    ScienceStudent(String sname, int n, int practicalMarks){
        super(sname, n);
        this.practicalMarks = practicalMarks;
    }

    void compute() {
        super.compute();
        total+=practicalMarks;
        avg=(double)total/n;
    }

    void displayPracticalMarks() {
        System.out.println("Practical Marks: "+ practicalMarks);
    }

}

class ArtsStudent extends STUDENT{
    String electiveSubject;

    ArtsStudent(String sname, int n, String electiveSubject){
        super(sname, n);
        this.electiveSubject = electiveSubject;
    }

}

class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of Science students: ");
        int n1 = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Enter no. of Arts students: ");
        int n2 = scanner.nextInt();
        scanner.nextLine();

        ScienceStudent[] s1 = new ScienceStudent[n1];
        ArtsStudent[] s2 = new ArtsStudent[n2];


        System.out.println("Enter Science student details: ");
        for(int i=0; i<n1; i++) {
            System.out.println("Enter student name: ");
            String name = scanner.nextLine();

            System.out.println("Enter no. of theory subjects: ");
            int n = scanner.nextInt();
            scanner.nextLine();

            System.out.println("Enter practical marks: ");
            int marks = scanner.nextInt();
            scanner.nextLine();

            s1[i]=new ScienceStudent(name, n, marks);
        }

        System.out.println("Enter Arts student details: ");
        for(int i=0; i<n2; i++) {
            System.out.println("Enter student name: ");
            String name = scanner.nextLine();

            System.out.println("Enter no. of theory subjects: ");
            int n = scanner.nextInt();
            scanner.nextLine();

            System.out.println("Enter elective Subject: ");
            String subject = scanner.nextLine();

            s2[i]=new ArtsStudent(name, n, subject);
        }

        for(int i=0; i<n1; i++) {
            s1[i].assign(scanner);
            s1[i].compute();
            s1[i].displayPracticalMarks();
            s1[i].display();
        }

        for(int i=0; i<n2; i++) {
            s2[i].assign(scanner);
            s2[i].compute();
            s2[i].display();
            System.out.println("Elective Subject: "+ s2[i].electiveSubject);
        }

        scanner.close();
    }
}

