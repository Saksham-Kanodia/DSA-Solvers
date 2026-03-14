import java.util.Arrays;
import java.util.Scanner;

public class STUDENT {
    String sname;
    String Id;

    STUDENT(String sname, String Id){
        this.sname = sname;
        this.Id = Id;
    }

    String extractInitials(){
        String initials = "";
        String[] words = sname.split(" ");
        for(int i=0; i<words.length; i++){
            initials += words[i].substring(0,1).toUpperCase();
        }
        return initials;
    }

    String removeWhitespace(){
        String modifiedName = "";
        char[] c = sname.toCharArray();
        for(int i=0; i<c.length; i++){
            if(c[i]== ' ')
                continue;
            else
                modifiedName += c[i];
        }
        return modifiedName;
    }

    void findSubstring(String sub){
        if(sname.contains(sub))
            System.out.println(sname);
    }

    void sortAlphabetically(String[] students){
        Arrays.sort(students);
    }

}

class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of Students: ");
        int n= scanner.nextInt();
        scanner.nextLine();

        STUDENT[] s = new STUDENT[n];
        for(int i=0; i<n; i++){
            System.out.println("Enter Student name: ");
            String name = scanner.nextLine();

            System.out.println("Enter Student Id: ");
            String Id = scanner.nextLine();

            s[i] = new STUDENT(name,Id);
        }

        for(int i=0; i<n; i++){
            System.out.println("Student name: " + s[i].sname);
            System.out.println("Student Id: " + s[i].Id);
            System.out.println("Student Initials: " + s[i].extractInitials());
            System.out.println("Removing whitespaces: " + s[i].removeWhitespace());
            System.out.println();
        }

        System.out.println("Enter substring to find: ");
        String sub = scanner.nextLine();
        for(int i=0; i<n; i++){
            s[i].findSubstring(sub);
        }

        System.out.println("Alphabetic order: ");
        String[] str = new String[s.length];
        for(int i=0; i<n; i++){
            str[i] = s[i].sname;
        }
        Arrays.sort(str);
        for(int i=0; i<n; i++){
            System.out.println(str[i]);
        }

        scanner.close();

    }
}
