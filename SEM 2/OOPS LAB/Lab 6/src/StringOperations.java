import java.util.Arrays;
import java.util.Scanner;

public class StringOperations {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String str = scanner.nextLine();

        //Display menu
        System.out.println("Menu: ");
        System.out.println("1.) Check Palindrome");
        System.out.println("2.) Write string in alphabetical Order");
        System.out.println("3.) Reverse the string");
        System.out.println("4.) Concatenate original and reversed string");
        System.out.println();

        //enter choice
        System.out.println("Enter your choice: ");
        int choice = scanner.nextInt();
        scanner.nextLine();

        switch(choice){
            case 1:
                String reversedWord = "";
                char[] c = str.toCharArray();
                for(int i=c.length -1; i>=0; i--){
                    reversedWord = reversedWord + c[i];
                }
                if(reversedWord.equalsIgnoreCase(str))
                    System.out.println("Yes,Palindrome");
                else System.out.println("No, not Palindrome");
                break;

            case 2:
                char[] c2 = str.toCharArray();
                Arrays.sort(c2);
                String alphabeticalOrder = new String(c2);
                System.out.println("Alphabetical Order: " + alphabeticalOrder);
                break;

            case 3:
                String rev = "";
                char[] c3 = str.toCharArray();
                for(int i=c3.length-1; i>=0; i--){
                    rev = rev + c3[i];
                }
                System.out.println("Reverse String: "+ rev);
                break;

            case 4:
                String rev2 = "";
                char[] c4 = str.toCharArray();
                for(int i=c4.length-1; i>=0; i--){
                    rev2 = rev2 + c4[i];
                }
                String concatenated = str.concat(rev2);
                System.out.println("Concatenated String: " + concatenated);
                break;

        }

        scanner.close();
    }
}
