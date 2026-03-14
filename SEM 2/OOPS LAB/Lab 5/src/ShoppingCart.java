import java.util.Scanner;

public class ShoppingCart {
    String ShoppingMall;
    Item[] item;
    int n;
    int count=0;

    ShoppingCart(String ShoppingMall, int n){
        this.ShoppingMall = ShoppingMall;
        this.n = n;
        item = new Item[n];
    }

    class Item{
        String itemName;
        int quantity;
        double price;

        void assign(Scanner scanner){
            System.out.println("Enter item name: ");
            itemName = scanner.nextLine();

            System.out.println("Enter item quantity: ");
            quantity = scanner.nextInt();
            scanner.nextLine();

            System.out.println("Enter item price: ");
            price = scanner.nextDouble();
            scanner.nextLine();
        }

        void displayItemDetails(){
            System.out.println("Item name: " + itemName);
            System.out.println("Item quantity: " + quantity);
            System.out.println("Item Price: " + price);
        }

    }

    void addItems(Scanner scanner){
        item[count] = new Item();
        item[count].assign(scanner);
        count++;
    }

    double calculateTotal(){
        double total = 0;
        for(int i=0; i<n; i++){
            total += (item[i].price * item[i].quantity);
        }

        return total;
    }

    void display(){
        System.out.println("Shopping Mall: " + ShoppingMall);
        System.out.println();
        for(int i=0; i<n; i++){
            item[i].displayItemDetails();
            System.out.println();
        }
        System.out.println("Total: " + calculateTotal());
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Shopping Mall Name: ");
        String mall = scanner.nextLine();

        System.out.println("Enter no. of items: ");
        int n= scanner.nextInt();
        scanner.nextLine();

        ShoppingCart cart = new ShoppingCart(mall,n);
        for(int i=0; i<n; i++){
            cart.addItems(scanner);
        }

        cart.display();

        scanner.close();
    }
}
