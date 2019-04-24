
public class Main {
	
	public static void main(String[] args) throws Exception {
		System.out.println("1a) " + fakRec(10));						//task 1 a)
		System.out.println("1b) " + binormalKoeffizientRec(5, 2));		//task 1 b)
		System.out.println("1c) " + lottoproblem(5, 2));				//task 1 c)
		//check if 110.1 == 110.1 -> true because all bytes are the same value
		System.out.println("2 6.5f == 6.5 : " + compare(6.5f, 6.5));		//task 2
		//check if 110.0110011 == 110.0110011001100110011 (length only representative) -> false because different value after decimal 
		System.out.println("2 6.4f == 6.4 : " + compare(6.4f, 6.4));		//task 2
		System.out.println("3 euklid(46, 28) : " + euklid(46, 28));			//task 3
		
		Schifffahrtsamt amt=new Schifffahrtsamt();
		Werft w1=new Werft();
		w1.produziereSchiff("Gertrut", 12.5, amt);
		Schiff sc1=new Schiff("Merlin", 45.9);
		amt.registriereSchiff(sc1);
		sc1.setKennzeichen(Schifffahrtsamt.getKennzeichen());
		amt.meldung("Havarie im Rhein bei Rheinkilometer 591.", 1);
		amt.meldung("Sonnenschein bei Rheinkilometer 650", 0);
		
		
	}
	
	private static long fakRec(long n) {			
		if(n == 0)	return 1;					//default case
		if(n > 0)	return n * fakRec(n - 1);	//recursion
		return 0;								//invalid input (negative integer)
	}
	
	private static long binormalKoeffizientRec(long n, long k) {
		if(0 <= n && n < k)	return 0;											//default case
		if(0 <= k && k < n)	return fakRec(n) / (fakRec(k) * (n - fakRec(k)));	//recursion
		return 0;																//invalid input
	}
	
	private static long lottoproblem(long n, long k) {
		return binormalKoeffizientRec(n, k) * fakRec(k);	//return binKoeffizient(n, k) * k!
	}
	
	private static boolean compare(float a, double b) {
		return a == b;										//simple comparison of float and double
	}
	
	private static int euklid(int a, int b) {
		if(a == 0) return b;	//default case
		while(b != 0)			//find smallest divider
		{
			if(a > b)
				a -= b;
			else 
				b -= a;
		}
		return a;				//return result
	}
	
	
}
