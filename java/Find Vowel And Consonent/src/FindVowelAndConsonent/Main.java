package FindVowelAndConsonent;
// Jan 27, 2022
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int i;
        Scanner input = new Scanner(System.in);

        System.out.println("Enter the string:");
        String s1 = input.nextLine();
        for (i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == 'a' || s1.charAt(i) == 'e' || s1.charAt(i) == 'i' || s1.charAt(i) == 'o' ||
                    s1.charAt(i) == 'u' || s1.charAt(i) == 'A' || s1.charAt(i) == 'E' ||  s1.charAt(i) == 'I' ||
                    s1.charAt(i) == 'O' ||  s1.charAt(i) == 'U') {
                System.out.println(s1.charAt(i) + " is vowel");
            }
            else {
                System.out.println(s1.charAt(i) + " is consonent");
            }
        }
    }
}
