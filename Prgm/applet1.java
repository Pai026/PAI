import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="applet1" width=500 height=500>
</applet>
*/
public class applet1 extends Applet implements ActionListener{
	TextField t;
	Boolean m=false;
	Button submit;
	String msg="";
	int k=1,l=0;
	public void init()
	{	submit=new Button("submit");
		t=new TextField(10);
		add(t);
		add(submit);
		submit.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{	int i=0;
		String s=ae.getActionCommand();
		msg=t.getText();
		String b="";
		if(s.equals("submit"))
		{
			int n=msg.length();
		for(i=n-1;i>=0;i--)
				b = b + msg.charAt(i); 
				 k=(msg.equalsIgnoreCase(b))?1:0;
		}
		l=1;

		repaint();
	}
	public void paint(Graphics g)
	{	if(l==0)
			g.drawString("hello",40,80);
		else{
			if(k==0)
				g.drawString("Not palindrome",40,80);
			else
				g.drawString("palindrome",40,80);
			}

	}

}