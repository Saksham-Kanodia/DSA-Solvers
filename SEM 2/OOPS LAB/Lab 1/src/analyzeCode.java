public class analyzeCode {
    public static void main(String[] args){

        //a.) int to double (implicit conversion)
        int x1=10;
        double y1=x1;
        System.out.println(y1);

        //b.) double to int (Conversion isn't allowed implicitly)
        double x2=10.5;
        //int y2 = x2; (Not allowed to convert implicity)

        //c.) double to int (Explicit conversion)
        double x3= 10.5;
        int y3 = (int) x3;
        System.out.println(y3);

    }
}
