import java.util.Random;

public class Die {
    private int sideUp;

    int getSideUp(){
        return sideUp;
    }

    void roll(){
        Random random = new Random();
        sideUp = random.nextInt(6)+1;
    }

}

class DieDemo{
    public static void main(String[] args){
        Die d1 = new Die();
        Die d2 = new Die();

        d1.roll();
        d2.roll();

        int sum = d1.getSideUp() + d2.getSideUp();
        System.out.println("Dice 1: " + d1.getSideUp());
        System.out.println("Dice 2: " + d2.getSideUp());
        System.out.println("The sum of two sides is: " + sum);
    }
}
