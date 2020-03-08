import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class NewSwing extends JApplet
{	String s;
	NewSwing()
	{
		JFrame F=new JFrame("Hello Welcome");
		JPanel P=new JPanel();
		F.setSize(100,100);
		F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		F.setVisible(true);
		JTextField F1=new JTextField(10);
		JButton B=new JButton("ADD");
		JTextField F2=new JTextField(10);
		P.add(F1);
		P.add(B);
		P.add(F2);
		F.add(P);
		F1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
			{
				repaint();
			}
		});
		B.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
			{
					s=F1.getText();
					F2.setText(s);
			}
		});
	}
	public static void main(String args[])
	{
		SwingUtilities.invokeLater(new Runnable(){
			public void run()
			{
			new NewSwing();
			}

		});

	}





}