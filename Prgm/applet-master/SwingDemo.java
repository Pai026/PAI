import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class SwingDemo extends JApplet
{
    SwingDemo(int size)
    {
        setLayout(new FlowLayout());
        JFrame frame=new JFrame("This is a Swing app");
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        JButton btn=new JButton("Click me! - "+size);
        frame.add(btn);
        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae)
            {
                new SwingDemo(size+1);
            }
        });

    }
    public static void main(String args[])
    {
        SwingUtilities.invokeLater(new Runnable(){
            public void run()
            {
                new SwingDemo(1);
            }
        });
    }
}
