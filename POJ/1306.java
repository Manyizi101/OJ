import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while(true){
            int a=cin.nextInt();
            int b=cin.nextInt();
            if(a==0 && b==0)
                return;
            BigInteger fir=factor(a);
            BigInteger sec=factor(a-b);
            BigInteger third=factor(b);
            BigInteger result=fir.divide(sec).divide(third);
            System.out.println(a+" things taken "+b+" at a time is "+result.toString()+" exactly.");
        }
    }
    
    public static BigInteger factor(int n){
        BigInteger goal=BigInteger.ONE;
        for(int i=n;i>=2;i--){
            goal=goal.multiply(new BigInteger(String.valueOf(i)) );
        }
        return goal;
    }

}
