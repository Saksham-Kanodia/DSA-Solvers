import java.util.Scanner;

public class STUDENT {
    String name;
    String Id;

    STUDENT(String name, String Id){
        this.name = name;
        this.Id = Id;
    }

    class Subject{
        String subjectName;
        int marks;

        void assign(Scanner scanner){
            System.out.println("Enter subject Name: ");
            subjectName = scanner.nextLine();

            System.out.println("Enter subject marks: ");
            marks = scanner.nextInt();
            scanner.nextLine();
        }

        void displaySubjectDetails(){
            System.out.println("Subject name: " + subjectName);
            System.out.println("Subject Marks: " + marks);
        }
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of subjects: ");
        int n= scanner.nextInt();
        scanner.nextLine();

        System.out.println("Enter Student name: ");
        String name = scanner.nextLine();
        System.out.println("Enter Student Id: ");
        String Id = scanner.nextLine();

        STUDENT student = new STUDENT(name,Id);
        STUDENT.Subject[] subject = new Subject[n];

        for(int i=0; i<n; i++){
            subject[i] = student.new Subject();
            subject[i].assign(scanner);
        }

        int total =0; double average;
        for(int i=0; i<n; i++){
            total+=subject[i].marks;
        }
        average = ((double)total/(double)n);

        for(int i=0; i<n; i++){
            subject[i].displaySubjectDetails();
        }
        System.out.println("Total: " + total);
        System.out.println("Average: "+ average);

        scanner.close();
    }
}
