
public class Main 
{
	public static void main(String[] args) throws Exception
	{
		java.util.Scanner sc = new java.util.Scanner(System.in);
		System.out.println("Eingabe: ");
		int k = sc.nextInt(); 	// liest eine Ganzzahl (int) ein
		System.out.println(++k); 	// Ausgabe a) erhöht die Eingabe um 1 und gibt sie aus
		System.out.println(k); 		// Ausgabe b) gibt den aktuelen Wert von k aus
		System.out.println(k++); 	// Ausgabe c) gibt k aus und erhöht ihn anschliessend um 1
		int k2 = 5;
		double result = (double) k2 / 2; 	// Stelle 1 typecast int als double
		System.out.println("5 / 2 = " + result); 	// Ausgabe d)
		boolean b = false;
		if(!b)	//b wurde nur auf falsch gesetzt und nicht verglichen 
		{
			System.out.println("b ist falsch."); 	// Ausgabe e)
			
		}
		else 
		{
			System.out.println("b ist wahr."); 		// Ausgabe f) war zuvor nicht erreichbar
		}
		System.out.println(b ? "b ist wahr" : "b ist falsch");
	}
	
	
}
