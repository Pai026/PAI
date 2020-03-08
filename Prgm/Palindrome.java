import java.io.*;
public class Palindrome
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b=new String();
		int n=a.length();
		for(int i=n-1;i>=0;i--)
				b = b + a.charAt(i); 
		
				System.out.println("Palindrome"+ a.equalsIgnoreCase(b));
			
				



	}




}