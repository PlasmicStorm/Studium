
public class Operatoren 
{
	public static void main(String [] args)
	{
		int a=15;int b=34;int c=1;
		System.out.println("1: "+ (a==b));		// a ≠ b deswegen false
		System.out.println("2: "+ (a==b-19));	// a = b - 19 deswegen true
		System.out.println("3: "+ (a^b));		// 1111 xor 100010 = 101101 = 45
		System.out.println("4: "+ (a++^b));		// 1111 xor 100010 = 101101 = 45 anschließend a um 1 erhöhen
		System.out.println("5: "+ (7<<++c));	// 111 << 2 bits 11100 = 28 = 7*2*2
		System.out.println("6: "+ (a=b=c=0x10));// a,b,c werden auf 16 gesetzt (Hexadecimal)
		System.out.println("7: "+ (1e1));		// 1 * 10^1 = 10
	}
}