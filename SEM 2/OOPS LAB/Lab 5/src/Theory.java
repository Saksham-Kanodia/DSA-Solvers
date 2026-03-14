public class Theory {
    //In Java, a nested class is any class defined inside another class.
    //Nested classes are a way to logically group classes that are only used in one place.
    //Nested classes improve encapsulation and readability, allowing related functionality to be tightly coupled.

    /*Syntax:
    class OuterClass{
    .....
         class InnerClass{
         ......
         }
     }*/

    /*Types Of Nested Classes:
    1.) Static Nested Classes:
    (i.) Declared with the static modifier.
    (ii.)Do not have access to instance members(non static members) of the enclosing class.
    (iii.)Can directly access the static memebers of the outer class.

    2.) Non-static Inner Classes:
    (i.) A nested class without the static modifier.
    (ii.) Have access to all members(static and non-static) of the enclosing class.
    (iii.) Require an instance of the outer class to be instantiated.
     */

    /*Example 1:
    class Bank{
    private static String bankName = "Global Bank";

    static class Account{
    private static String accountNumber;
    private double balance;

    Account(String accountNumber, double balance){
    this.accountNumber = accountNumber;
    this.balance = balance;
    }

    void displayAccountDetails(){
    System.out.println("Bank Name: " + bankName);
    System.out.println("Account Number: " + accountNumber);
    System.out.println("Balance: $" +balance);
    }
    }
    }

    public class Main{
        public static void main(String[] args){
        Bank.Account account = new Bank.Account("12345", 2500.75);
        account.displayAccountDetails();
        }
    }
     */

}

class Example2{
    /*class University{
    private String universityName;

    University(String universityName){
    this.universityName= universityName;
    }

    class Department{
    private String departmentName;

    Department(String departmentName){
    this.departmentName = departmentName;
    }

    void displayDetails(){
    System.out.println("University: " + universityName);
    System.out.println("Department: " + departmentName);
    }
    }
    }

   public class Main{
          public static void main(String[] args){
          University university = new University("MAHE");
          University.Department department = university.new Department("CSE");

          department.displayDetails();
          }
   }
     */
    
}

class InnerClasses{
    /*An inner class in Java is a class defined within another class.
    Inner classes are primarily used for logically grouping classes that are
    only used in one place, improving encapsulation and readability.

    Syntax:
          class OuterClass{
          .......
            static class StaticNestedClass{
            ........
            }
            class InnerClass{
            ..........
            }
          }
     */

    /* Types of inner classes include:-

    1.) Non-Static inner classes: Have access to the enclosing class's instance
        members and methods.
    2.) Local Inner classes: Defined within a method or block; they exist only within that scope.
    3.) Anonymous Inner Classes: Declared and instantiated simultaneously, often used for event handling
    or functional interface implementations.
     */
}

class Example3{
    // Non-static Inner Classes.

    /*
    class Library{
        private String name;
        private String address;

        Library(String name, String address){
        this.name = name;
        this.address = address;
        }

        void displayLibraryDetails(){
              System.out.println("Library name: " + name);
              System.out.println("Library address: " +address);
        }

        class Book{
             private String title;
             private String author;

             Book(String title, String author){
             this.title = title;
             this.author = author;
             }

             void displayBookDetails(){
             System.out.println("Book Title: " + title);
             System.out.println("Book author: " + author);
             }

        }

    }

    public class Main{
         public static void main(String[] args){
            Library library = new Library("MIT CENTRAL LIBRARY", "MIT MANIPAL");
            library.displayDetails();

            Library.Book book = library.new Book("Fundamentals of Software Engineering","IAN SOMMERVILLE");
            book.displayDetails();
         }
    }
     */

}
