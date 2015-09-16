import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String args[]) {
        int n;
        BigInteger s;
        BigInteger eight = BigInteger.valueOf(8);
        BigInteger seven = BigInteger.valueOf(7);
        BigInteger one = BigInteger.valueOf(1);
        Scanner cin = new Scanner( System.in );
        n = cin.nextInt();
        int cs=0;
        while ( n-- != 0 ) {
            cs++;
            s = cin.nextBigInteger();
            System.out.print("Case #");
            System.out.print(cs);
            System.out.print(": ");
            System.out.print((s.multiply((s.multiply(eight)).subtract(seven))).add(one));
            System.out.print("\n");
        }
        return;
    }
}