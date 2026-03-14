public class Counter {
    static int count=0;

    Counter(){
        count++;
    }

    static void showCount(){
        System.out.println("The number of objects created is: " + count);
    }

    public static void main(String[] args){
        Counter c1 = new Counter();
        Counter.showCount();

        Counter c2 = new Counter();
        Counter.showCount();

        Counter c3 = new Counter();
        Counter.showCount();
    }

}
