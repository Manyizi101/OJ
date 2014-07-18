import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            if (n == 0)
                break;
            BigInteger aBigInteger = scanner.nextBigInteger();
            BigInteger bBigInteger = scanner.nextBigInteger();
            BigInteger a = new BigInteger(aBigInteger.toString(), n);
            BigInteger b = new BigInteger(bBigInteger.toString(), n);
            BigInteger cBigInteger = a.divide(b);
            BigInteger mBigInteger = a.subtract(cBigInteger.multiply(b));
            System.out.println(mBigInteger.toString(n));
        }
    }
}