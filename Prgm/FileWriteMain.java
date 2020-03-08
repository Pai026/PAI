import java.io.*;
public class FileWriteMain
{
    public static void main(String[] args) throws FileNotFoundException,IOException
    {
        int n;
        FileOutputStream even=new FileOutputStream("even.txt");
        FileOutputStream odd=new FileOutputStream("odd.txt");
        for(int i=0;i<args.length;i++)
        {
            n=Integer.parseInt(args[i]);
            if(n%2==0)
                even.write((char)n);
            else
                odd.write((char)n);
        }
    }
}