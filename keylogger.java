import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.time.LocalDateTime;

public class keylogger {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            FileWriter writer = new FileWriter("keystrokes.log", true);

            while (true) {
                System.out.print("Enter text (EXIT to stop): ");
                String input = sc.nextLine();

                String time = LocalDateTime.now().toString();
                writer.write("[" + time + "] " + input + "\n");
                writer.flush();

                if (input.equals("EXIT")) {
                    break;
                }
            }

            writer.close();
            sc.close();

            System.out.println("Data saved successfully.");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
