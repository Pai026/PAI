import java.io.*;
import java.lang.ArithmeticException;
class ArithmeticOperations
{
    int add(int a,int b)
    {
        return (a+b);
    }
    int sub(int a,int b)
    {
        return (a-b);
    }
    int mul(int a,int b)
    {
        return (a*b);
    }
    int div(int a,int b) throws ArithmeticException
    {
        if(b==0)
            throw new ArithmeticException();
        return (a/b);
    }
}
public class ExceptionThrowMain
{
    public static void main(String[] args)
    {
        ArithmeticOperations op=new ArithmeticOperations();
        System.out.println(op.add(1,2));
        System.out.println(op.sub(2,2));
        System.out.println(op.mul(3,4));
        System.out.println(op.div(2,0));
    }
}