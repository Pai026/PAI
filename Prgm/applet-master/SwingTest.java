import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
class SwingDemo extends JApplet
{
    SwingDemo(int size,String j)
    {
        setLayout(new FlowLayout());
        JFrame frame=new JFrame(j);
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        JButton btn=new JButton("Click me! - "+size);
        frame.add(btn);
        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae)
            {
                new SwingDemo(size+1,j);
            }
        });

}
}
public class SwingTest extends JApplet
{	String str;
    SwingTest(int size)
    {	
        setLayout(new FlowLayout());
        JFrame frame=new JFrame("This is a Swing app");
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        JPanel p = new JPanel();
    JTextField text=new JTextField(15);
    
	JButton btn=new JButton("Click Me!!!");
	p.add(text);
    p.add(btn);
    frame.add(p);
   	text.addActionListener(new ActionListener(){
	 public void actionPerformed(ActionEvent ae)
            {
		str=text.getText();
	    }
	});
        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae)
            {
                new SwingDemo(size+1,str);
            }
        });

    }

    public static void main(String args[])
    {
        SwingUtilities.invokeLater(new Runnable(){
            public void run()
            {
                new SwingTest(1);
            }
        });
    }
}

