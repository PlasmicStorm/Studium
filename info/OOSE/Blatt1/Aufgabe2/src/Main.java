
public class Main 
{
	public static void main(String[] args) throws Exception
	{
		System.out.print("Wie ist dein Name? ");
		String name = Input.readString();
		System.out.println("Hallo " + name + "!");
	}
}