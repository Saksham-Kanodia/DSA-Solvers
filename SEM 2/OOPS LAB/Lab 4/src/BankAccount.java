import java.util.Scanner;

public class BankAccount {
    String Depositor;
    String AccountNumber;
    String AccountType;
    double balance;
    static double rate;

    //default constructor
    BankAccount(){
        Depositor = "Saksham Kanodia";
        AccountNumber = "1234567";
        AccountType = "Savings Account";
        balance = 10000000;
        rate = 12;
    }

    //parameterized constructor
    BankAccount(String name, String number, String type, double amount, double interest){
        Depositor = name;
        AccountNumber = number;
        AccountType = type;
        balance = amount;
        rate = interest;
    }

    void deposit(Scanner scanner){
        System.out.println("Enter amount to deposit: ");
        double deposit = scanner.nextDouble();
        scanner.nextLine();

        balance = balance + deposit;
    }

    void withdraw(Scanner scanner){
        System.out.println("Enter amount to withdraw: ");
        double withdrawal = scanner.nextDouble();
        scanner.nextLine();

        double minBalance = 12000;

        if((balance - withdrawal) >= minBalance)
            balance = balance - withdrawal;
        else
            System.out.println("Insufficient Balance.");
    }

    void display(){
        System.out.println("Depositor: " + Depositor);
        System.out.println("Account Number: " + AccountNumber);
        System.out.println("Account Type: " + AccountType);
        System.out.println("Balance: " + balance);
    }

     static void displayInterestRate(){
        System.out.println("Interest rate: " + rate + "%");
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        //default constructor
        BankAccount b1 = new BankAccount();
        b1.deposit(scanner);
        b1.withdraw(scanner);
        b1.display();
        b1.displayInterestRate();
        System.out.println();

        //parameterized constructor
        BankAccount b2 = new BankAccount("Madhav Kanodia", "251090052618", "Savings Account",10000000, 12);
        b2.deposit(scanner);
        b2.withdraw(scanner);
        b2.display();
        b2.displayInterestRate();

        scanner.close();
    }

}
