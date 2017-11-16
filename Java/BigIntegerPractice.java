import java.util.Scanner;
import java.math.BigInteger;

class BigIntegerPractice
{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        while (s.hasNext())
        {
            BigInteger a = new BigInteger(s.next());
            System.out.println("BigInteger A: " + a);
            BigInteger b = new BigInteger(s.next());
            System.out.println("BigInteger B: " + b);

            System.out.println(a.add(b));
            System.out.println(a.subtract(b));
            System.out.println(a.multiply(b));
            System.out.println(a.divide(b));
        }
    }
}