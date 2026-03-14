import java.util.Scanner;

public class STUDENT {
    String sname;
    int n;
    int[] marks_array;
    int total;
    double avg;

    void assign(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name: ");
        sname = scanner.nextLine();

        System.out.println("Enter no. of subjects: ");
        n= scanner.nextInt();
        scanner.nextLine();

        marks_array = new int[n];
        System.out.println("Enter marks of subjects: ");
        for(int i=0; i<n; i++){
            marks_array[i]=scanner.nextInt();
        }
        scanner.nextLine();

        scanner.close();
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

    public static void main(String[] args){
        STUDENT s1 = new STUDENT();
        s1.assign();
        s1.compute();
        s1.display();
    }
}
