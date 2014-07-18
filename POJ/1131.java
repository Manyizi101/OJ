import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String str, ors;
        BigDecimal x, y, z;
        while (cin.hasNext()) {
            ors = cin.next();
            str = ors.substring(ors.indexOf(".") + 1, ors.length());
            z = new BigDecimal(0);
            y = new BigDecimal(1);
            for (int i = 0; i < str.length(); i++) {
                x = new BigDecimal(str.charAt(i) - '0');
                y = y.multiply(new BigDecimal(8));
                x = x.divide(y, str.length() * 3, RoundingMode.HALF_UP);
                z = z.add(x);
            }
            System.out.println(ors + " [8] = " + z + " [10]");
        }
        cin.close();
    }
}