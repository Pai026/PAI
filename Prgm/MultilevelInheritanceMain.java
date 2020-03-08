import java.io.*;
class A
{
    int a,b;
    A(int x,int y)
    {
        a=x; b=y;
    }
}
class B extends A
{
    B(int x,int y)
    {
        super(x,y);
    }
    int sum()
    {
        return a+b;
    }
}
class C extends B
{
    C(int x,int y)
    {
        super(x,y);
    }
    void print()
    {
        System.out.println(sum());
    }
}
public class MultilevelInheritanceMain
{
    public static void main(String[] a)
    {
        new C(1,2).print();
    }
}