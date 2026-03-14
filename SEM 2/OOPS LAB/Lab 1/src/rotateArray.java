import java.util.Scanner;

public class rotateArray {
    public static void main(String[] args){
        // program to rotate an array left/right
        Scanner scanner = new Scanner(System.in);

        //declare array size
        System.out.println("Enter the size of the array: ");
        int n= scanner.nextInt();

        //input array elements
        System.out.println("Enter the array elements: ");
        int arr[] = new int[n];
        for(int i=0; i<n; i++) {
            arr[i] = scanner.nextInt();
        }
        int rightArr[]=arr.clone();

        //specify no. of steps by which left shift/right shift
        System.out.println("Specify no. of steps by which you want to rotate: ");
        int d = scanner.nextInt();

        //left rotate the array
        for(int i=0; i<d; i++){
            int temp=arr[0];
            for(int j=0; j<n-1; j++){
                arr[j]=arr[j+1];
            }
            arr[n-1]=temp;
        }

        System.out.println("The left rotated array is: ");
        for(int i=0; i<n; i++){
            System.out.print(arr[i] + " ");
        }

        //right rotate the array
        for(int i=0; i<d; i++){
            int temp=rightArr[n-1];
            for(int j=n-1; j>0; j--){
                rightArr[j]=rightArr[j-1];
            }
            rightArr[0]=temp;
        }

        System.out.println();
        System.out.println("The right rotated array is: ");
        for(int i=0; i<n; i++){
            System.out.print(rightArr[i] + " ");
        }
    }
}
