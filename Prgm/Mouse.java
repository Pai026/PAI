import java.awt.*;
import java.applet.*;
import java.awt.event.*;
/*<applet code=Mouse width=100 height=500>
</applet>
*/
public class Mouse extends Applet implements MouseListener,MouseMotionListener
{	int x,y;
	public void init()
	{
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	public void mouseMoved(MouseEvent me)
	{
		x=me.getX();
		y=me.getY();
		repaint();

	}
	public void paint(Graphics g)
	{
		g.drawString(x+" "+y,100,200);

	}
	 public void mouseEntered(MouseEvent me){}
    public void mouseExited(MouseEvent me){}
    public void mouseClicked(MouseEvent me){
    showStatus("Mouse Clicked");}
    public void mouseDragged(MouseEvent me){
    showStatus("Mouse Dragged");}
    public void mousePressed(MouseEvent me){
    showStatus("Mouse Pressed");}
    public void mouseReleased(MouseEvent me){
    showStatus("Mouse Released");



}
}