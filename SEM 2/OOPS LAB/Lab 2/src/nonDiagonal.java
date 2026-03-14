import java.util.Scanner;

public class nonDiagonal {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the order of matrix you want: ");
        int n = scanner.nextInt();

        int mat[][] = new int[n][n];
        System.out.println("Enter the matrix elements:");
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++){
                mat[i][j]=scanner.nextInt();
            }
        }

        System.out.println("The input matrix is: ");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }

        //non principal diagonal elements
        int sum=0;
        System.out.println("The non principal diagonal elements are: ");
        for(int i=0; i<n; i++){
            sum+=mat[i][n-1-i];
            System.out.print(mat[i][n-1-i] + " ");
        }
        System.out.println("\nThe sum of non principal diagonal elements are: " + sum);

        scanner.close();
    }
}
