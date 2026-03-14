import java.util.Scanner;

public class Weather {

    static class Forecast{
        String city;
        double temperature;
        double humidity;

        void assign(Scanner scanner){
            System.out.println("Enter city Name: ");
            city = scanner.nextLine();

            System.out.println("Enter temperature: ");
            temperature = scanner.nextDouble();
            scanner.nextLine();

            System.out.println("Enter humidity: ");
            humidity = scanner.nextDouble();
            scanner.nextLine();
        }

        void forecast(){
            System.out.println("City: " + city);
            System.out.println("Temperature: " + temperature);
            System.out.println("Humidity: " + humidity);

            if(temperature >= 40) System.out.println("Sunny");
            else if(temperature>=25 && humidity>=35) System.out.println("Rainy");
            else System.out.println("Cloudy");
        }

    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter no. of cities: ");
        int n= scanner.nextInt();
        scanner.nextLine();

        Weather.Forecast[] forecast = new Weather.Forecast[n];

        for(int i=0; i<n; i++){
            forecast[i] = new Weather.Forecast();
            forecast[i].assign(scanner);
        }

        for(int i=0; i<n; i++){
            forecast[i].forecast();
            System.out.println();
        }

        scanner.close();
    }

}
