import java.util.Scanner;

public class Mixer {
    int[] arr;

    void accept(Scanner scanner){
        System.out.println("Enter the no. of array elements: ");
        int n= scanner.nextInt();

        System.out.println("Enter the array elements: ");
        arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = scanner.nextInt();
        }
        scanner.nextLine();
    }

    Mixer mix(Mixer A){
        Mixer result = new Mixer();

        int n1= this.arr.length;
        int n2 = A.arr.length;

        result.arr=new int[n1+n2];

        int i=0,j=0,k=0;

        while(i<n1 && j<n2){
            if(this.arr[i]<A.arr[j]){
                result.arr[k++]=this.arr[i++];
            }
            else if(A.arr[j]<this.arr[i]){
                result.arr[k++]=A.arr[j++];
            }
            else{
                result.arr[k++]=this.arr[i++];
                j++;
            }
        }
        while(i<n1){
            result.arr[k++]=this.arr[i++];
        }
        while(j<n2){
            result.arr[k++]=A.arr[j++];
        }
         return result;
    }

    void display(){
        System.out.println("The array elements are: ");
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        Mixer m1= new Mixer();
        m1.accept(scanner);

        Mixer m2= new Mixer();
        m2.accept(scanner);

        Mixer m3 = m2.mix(m1);

        m3.display();
    }
}
