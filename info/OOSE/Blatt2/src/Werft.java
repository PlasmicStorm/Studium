
public class Werft {
	
	public void produziereSchiff(String pName, double pLaenge, Schifffahrtsamt pAmt) {
		Schiff schiffTemp = new Schiff(pName, pLaenge);
		pAmt.registriereSchiff(schiffTemp);
		schiffTemp.setKennzeichen(Schifffahrtsamt.getKennzeichen());
	}
}
