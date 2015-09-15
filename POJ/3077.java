import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String args[]) {
        int n;
        BigInteger s;
        Scanner cin = new Scanner( System.in );
        n = cin.nextInt();
        while ( n-- != 0 ) {
            s = cin.nextBigInteger();
            BigInteger eight = BigInteger.valueof(8);
            BigInteger seven = BigInteger.valueof(7);
            BigInteger one = BigInteger.valueof(1);
            System.out.println( s.multiply(s).multiply(eight).subtract(seven.multiply(s)).add(one) );
        }
        return;
    }
}