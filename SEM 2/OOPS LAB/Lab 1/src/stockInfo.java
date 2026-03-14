import java.util.Scanner;

public class stockInfo {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        //specify no. of products
        System.out.println("Enter the no. of products you have: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        //Input product name
        System.out.println("Enter product name: ");
        String name[] = new String[n];
        for(int i=0; i<n; i++){
            name[i]=scanner.nextLine();
        }

        //Input product price
        System.out.println("Enter product price: ");
        double price[] = new double[n];
        for(int i=0; i<n; i++){
            price[i]=scanner.nextDouble();
        }

        //Input product quantity
        System.out.println("Enter product quantity: ");
        int quantity[] = new int[n];
        for(int i=0; i<n; i++){
            quantity[i]=scanner.nextInt();
        }

        //ask what customer wants
        System.out.println("Enter the no. of items the customer wants: ");
        int n1=scanner.nextInt();
        scanner.nextLine();

        //input product name
        System.out.println("Enter product name: ");
        String name1[] = new String[n1];
        for(int i=0; i<n1; i++){
            name1[i]=scanner.nextLine();
        }

        //input product quantity
        System.out.println("Enter product quantity: ");
        int quantity1[] = new int[n1];
        for(int i=0; i<n1; i++){
            quantity1[i]=scanner.nextInt();
        }

        //calculate bill
        double bill=0;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n; j++){
                if(name1[i].equals(name[j])) {
                    if (quantity1[i] <= quantity[j]) bill += quantity1[i] * price[j];
                    else System.out.println("Insufficient quantity for "+name1[i]);
                }
            }
        }

        System.out.println("The total bill is: "+bill);
    }
}
