import java.io.*;
import java.util.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String args[])throws Exception {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            BigDecimal r = cin.nextBigDecimal();
            int n = cin.nextInt();
            r = r.pow(n).stripTrailingZeros();
            String m_string = r.toPlainString();
            if (m_string.charAt(0) == '0')
                m_string = m_string.substring(1);
            System.out.println(m_string);
        }
    }
}