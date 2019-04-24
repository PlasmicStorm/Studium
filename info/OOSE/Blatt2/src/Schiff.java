
public class Schiff {

	private String name, kennzeichen;
	private double laenge;
	
	public Schiff(String pInput, double pLaenge) {
		name 	= pInput;
		laenge	= pLaenge;
	}
	
	public void setKennzeichen(String pKennzeichen) {
		kennzeichen = pKennzeichen;
	}
	
	public void empfangeNachricht(String msg) {
		System.out.println(	"(" + name + ") [" + kennzeichen + "] Nachricht: " + msg);
	}
}
