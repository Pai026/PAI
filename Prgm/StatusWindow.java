import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*
<applet code=StatusWindow width=300 height=500>
</applet>
*/
public class  StatusWindow extends Applet implements ActionListener{
Button B1;
TextField F1,F2;
String msg,msg2;
Font f;
public void init () { 
	f=new Font("Aharoni",Font.PLAIN,32);
	F1=new TextField("Username",10);
	F2=new TextField(10);
	F2.setEchoChar('?');
	B1=new Button("submit");
	add(F1);
	add(F2);
	add(B1);
    B1.addActionListener(this);
    F1.addActionListener(this);
    F2.addActionListener(this);
}
public void actionPerformed(ActionEvent ae)
{	String s=ae.getActionCommand();
	if(s.equals("submit"))
	{	String s1=F1.getText();
		msg="Username "+s1;
		String s2=F2.getText();
		msg2="Password "+s2;
	}
	repaint();
}
public void paint(Graphics g) {	
g.drawString (msg, 100, 200);
g.drawString(msg2,105,250);

showStatus ("This is shown in the status window."); 
}
}