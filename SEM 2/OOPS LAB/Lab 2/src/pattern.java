import java.util.Scanner;

public class pattern {

    public static void nestedFor(int rows){
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=i; j++){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static void forEach(int rows){
        int[] arr = new int[rows];
        for(int i=0; i<rows; i++){
            arr[i]=i+1;
        }

        for(int num:arr){
            for(int j=1; j<=num; j++){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the no. of rows: ");
        int rows = scanner.nextInt();

        forEach(rows);
        scanner.close();
    }
}
