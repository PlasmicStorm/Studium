
public class Schifffahrtsamt {
	
	private Schiff[] registrierteSchiffe = new Schiff[50];
	
	public void registriereSchiff(Schiff pSchiff) {
		for(int i = 0; i < registrierteSchiffe.length; i++) 
		{
			if(registrierteSchiffe[i] == null) 
			{
				registrierteSchiffe[i] = pSchiff;
				return;
			}
		}
		System.out.println("ERROR: Array is full");
	}
	
	public void meldung(String nachricht, int dringlichkeit) {
		if(dringlichkeit != 1)
			return;
		for(int i = 0; i < registrierteSchiffe.length; i++) 
		{
			if(registrierteSchiffe[i] == null) 
				return;
			registrierteSchiffe[i].empfangeNachricht(nachricht);
		}
	}
	
	
	public static String getKennzeichen() {
		java.util.Random rnd = new java.util.Random();
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < 6; i++) 
		{
			sb.append((char)((rnd.nextInt(25)+65)));
		}
		return sb.toString();
	}
}
