import java.io.*;
import java.util.*;
import java.lang.Math;
public class Test{
	public static void main(String args[])
	{
		int a[]=new int[10];
		int i;
		for(i=0;i<args.length;i++){
		 a[i]=Integer.parseInt(args[i]);
		}
		for(i=0;i<args.length;i++){
			System.out.println(Math.sqrt(a[i]));
		}
		
	}
}