import java.io.*;
public class ExceptionTestMain
{
    public static void main(String[] args)
    {
        try{
            System.out.println(Integer.parseInt(args[0])/Integer.parseInt(args[1]));
        }
        catch(ArithmeticException e)
        {
            System.out.println("Divide by Zero not possible!");
            e.printStackTrace();
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Expected 2 arguments!");
            e.printStackTrace();
        }
        catch(NumberFormatException e)
        {
            System.out.println("Expected 2 numbers as arguments!");
            e.printStackTrace();
        }
    }
}