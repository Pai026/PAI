import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*<applet code="Item" width=500 height=500>
</applet>
*/
public class Item extends Applet implements ItemListener
{
	Checkbox B1,B2;
	String msg,msg1;
	public void init()
	{
		B1=new Checkbox("Microsoft");
		B2=new Checkbox("Linux");
		add(B1);
		add(B2);
		B1.addItemListener(this);
		B2.addItemListener(this);
	}
	public void itemStateChanged(ItemEvent ie)
	{
		repaint();
	}
	public void paint(Graphics g)
	{
		g.drawString("Current State",100,200);
		msg="Microsoft"+B1.getState();
		g.drawString(msg,100,250);
		msg1="Linux"+B2.getState();
		g.drawString(msg1,100,300);

	}




}