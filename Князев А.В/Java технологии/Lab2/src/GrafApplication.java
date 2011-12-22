import java.awt.*;
import java.awt.event.*;

public class GrafApplication {
	public static void main(String[] args) {
		������������ gf = new ������������("����");
		gf.setSize(600, 400);
		gf.setVisible(true);
	}
}

class ��������� {
	int �������A, �������D;
	int �����B, �����C;
	boolean ������������=false;
	void ���������������������(int n)
	{
		if(�������A>n||�������D>n||�����B>n||�����C>n) ������������=false;
	}
}

class ��������������� extends Dialog {
	��������� params;
	TextField pt1, pt2, ln1, ln2;
	public ���������������(final ��������� params, Frame parent, String title){
		super(parent,title,true);
		this.params=params;
		setLayout(new GridLayout(3,3,10,5));
		setSize(400,120);
		Button btOk=new Button("��"), btCancel=new Button("������");
		Label lbPoints=new Label("�������:"), lbLine=new Label("����� ����� ���������:");
		pt1=new TextField();
		pt2=new TextField();
		ln1=new TextField();
		ln2=new TextField();
		add(lbPoints);add(pt1);add(pt2);
		add(lbLine);add(ln1);add(ln2);
		add(btOk);add(btCancel);
		btOk.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ev) throws NumberFormatException {
				params.�������A = Integer.parseInt(pt1.getText());
				params.�������D = Integer.parseInt(pt2.getText());
				params.�����B = Integer.parseInt(ln1.getText());
				params.�����C = Integer.parseInt(ln2.getText());
				params.������������=true;
				dispose();
				setVisible(false);
			}
		});
		btCancel.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ev){
				dispose();
				setVisible(false);
			}
		});
		
	}
}

class ������������ extends Frame implements ActionListener, MouseListener, ComponentListener {
	��������� ���������;
	���� ����;
	����� �����;
	int ������������������=-1;
	Label ���������������;
	
	public ������������(String title) {
		super(title);
		��������� = new ���������();
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we){
				System.exit(0);
			}
		});
		addMouseListener(this);
		addComponentListener(this);
		setLayout(new BorderLayout());
		���������������=new Label("������� ����");
		���������������.setBackground(new Color(242,242,242));
		add(���������������,BorderLayout.SOUTH);
		���� = new ����();
		MenuBar mb = new MenuBar();
		Menu ���� = new Menu("����");
		MenuItem ��������� = new MenuItem("����� ����");
		����.add(���������);
		MenuItem ����� = new MenuItem("�����");
		����.add(�����);
		mb.add(����);
		
		Menu ����� = new Menu("�����");
		MenuItem �������� = new MenuItem("���������...");
		�����.add(��������);
		MenuItem ������� = new MenuItem("�������...");
		�����.add(�������);
		mb.add(�����);
		
		setMenuBar(mb);
		�����.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				System.exit(0);
			}
		});
		final ������������ f=this;
		��������.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				Dialog pd = new ���������������(���������, f,"���������...");
				pd.setVisible(true);
				���������.���������������������(����.����������������);
				f.repaint();
			}
		});
		�������.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				���������������.setText("����� ����, ���������� ����� ������� a � d � ����� b c");
			}
		});
		���������.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				����.��������();
	            ���������.������������=false;
				f.repaint();
			}
		});
	}
	public void actionPerformed(ActionEvent ev) {
		repaint();
	}
	public void componentResized(ComponentEvent e) {
		repaint();
	}
	public void paint(Graphics g){
		if (����.����������������==0) return;
		����� = new �����(����.����������������, this.getWidth(), this.getHeight() - 70, g);

		double a=0;
		for(int j=0;j<����.����������������;j++)
		 {
           for (int k=0;k<����.����������������;k++)
           if(����.���������(j,k))
               �����.����������������(j,k);
           a+=�����.step;
		 }
		if(���������.������������)
		 {  
			g.setColor(Color.yellow);
			if(����.�����_�_�������(�����,���������.�������A,���������.�����B,���������.�����C,���������.�������D))
				this.���������������.setText("���� ������.");
			else this.���������������.setText("��� ����� ������.");
			g.setColor(Color.black);
		 }
		for(int j=0;j<����.����������������;j++)
           �����.�����������������(j);
	}
	
	public void mouseClicked(MouseEvent arg0) {}
	public void mouseEntered(MouseEvent arg0) {}
	public void mouseExited(MouseEvent arg0) {}
	public void mousePressed(MouseEvent e) {
		if (����.����������������==0) { ����.������������(); this.repaint(); return; }
        int ����������������� = �����.���������XY(e.getX(), e.getY());
        if (����������������� == -1) { ����.������������(); this.repaint(); }
        ������������������ = �����������������;
	}
	public void mouseReleased(MouseEvent e) {
		if (����.���������������� == 0) { ����.������������(); this.repaint(); return; }
        int ����������������� = �����.���������XY(e.getX(), e.getY());
        if (����������������� != -1 && ������������������ != -1) ����.����������(�����������������, ������������������);
        this.repaint();
        ������������������=-1;
	}
	public void componentHidden(ComponentEvent arg0) {}
	public void componentMoved(ComponentEvent arg0) {}
	public void componentShown(ComponentEvent arg0) {}
}
class ����� 
{
	private int cx,cy;//����� ������
    private int n,r,R;//���������� ������ �����, ������ �������, ������ ���������� �������� ������ ������
    public double step;//��� ������� R ��� �������� � ��������� �������
	private Graphics g;
	private final int st=40;//������ ������
	
    public �����(int n, int mx, int my, Graphics g)
    {
        this.n = n;
        this.cx = mx / 2;
        this.cy = my / 2;
        int rr=(cx<cy?cx:cy);
        int bb=(rr/n)>>1;
        this.R = (int)(rr / (1 + Math.sin(Math.PI / n)));
        this.r = rr - R - bb;
		if(r<0)r=-r;
        this.step = 2 * Math.PI / n;
        this.g = g;
    }
    private void �����(int x,int y,int xx,int yy)
    {
		g.drawLine(x,st+y,xx,st+yy);
    }
    public void ����������������(int i,int j)
    {
        int x = (int)(cx + R * Math.cos(step * j)), y = (int)(cy + R * Math.sin(step * j));
        int xx = (int)(cx + R * Math.cos(step * i)), yy = (int)(cy + R * Math.sin(step * i));
        �����(x,y,xx,yy);
    }
    public void �����������������(int j)
    {
            int x=(int)(cx+R*Math.cos(step*j)), y=(int)(st+cy+R*Math.sin(step*j));
			g.setColor(Color.white);
            g.fillOval(x-r,y-r,2*r,2*r);
			g.setColor(Color.black);
            g.drawOval(x-r,y-r,2*r,2*r);
			String s= String.valueOf(j);
			int dx=3*(j>9?2:1), dy=-4;
			g.drawString(s,x-dx,y-dy);
    }
    public int ���������XY(int X, int Y)
    {
    	int res = -1;
    	double a = 0;
        for (int j = 0; j < n; j++)
        {
            int x = (int)(cx + R * Math.cos(a)), y = (int)(st+cy + R * Math.sin(a));
            if ((X - x) * (X - x) + (Y - y) * (Y - y) <= r * r)
                res = j;
            a += step;
        }
        return res;
    }
}
class ����
{
    private boolean[][] �������C��������=new boolean[100][100];  //use: contact[max(i,j),min(i,j)]
    public int ���������������;
    
    public int ����������������;
    public void ��������() {for(int i =0;i<100;++i) for(int j =0;j<100;++j) �������C��������[i][j]=false; ����������������=0;���������������=0;}
	public ����() { ��������(); }
    public void ����������(int a, int b) { �������C��������[a>b?a:b][a>b?b:a]=true;���������������++; }
    public boolean ���������(int a, int b){ return �������C��������[a>b?a:b][a>b?b:a]; }
    public int ������������() {return ����������������++;}
    // ����� ����� ������� ���� ����� ������� � d � ����� b c
    private int[] �������� = new int[100];
    public boolean �����_�_�������(����� �����,int a, int b, int c, int d)
    {
            int ������������_�����=0;
            for(int i=0;i<100;i++)
                    ��������[i]=-1;
            int[] ������� = new int[100];
            ��������[a]=-2;
            int �������_�������=a;
            �������[0]=a;
            int �������_�����=1;
            int ���������_�������=0;
            int[] ���� = new int[1];
			boolean �����_��������=false;
			do
            {
                    if(���������_�������<����������������)
                    for(;���������_�������<����������������;���������_�������++)
                    if(���������(�������_�������,���������_�������)) break;
                    if(���������_�������<����������������)
                    {
                            if(��������[���������_�������]==-1)
                            {
                                    // ��� ������
                                    �������[�������_�����++]=�������_�������;
                                    ��������[���������_�������]=�������_�������;
                                    �������_�������=���������_�������;
                                    ���������_�������=-1;
                                    if (�������_������� == b && ��������[c] == -1 && ���������(b,c)) 
                                    { 
                                        �����_�������� = true; 
                                        �������[�������_�����++] = �������_�������; 
                                        ��������[c] = �������_�������; 
                                        �������_������� = c; 
                                    }
                                    else
                                        if (�������_������� == c && ��������[b] == -1 && ���������(c, b)) 
                                        { 
                                            �����_�������� = true; 
                                            �������[�������_�����++] = �������_�������; 
                                            ��������[b] = �������_�������; �������_������� = b; 
                                        }
                            }
							if(���������_�������==a&&��������[d]!=-1&&�����_��������&&������������_�����<�������_�����)
                            {
                                ������������_����� = �������_�����;
                                
                                ���� = new int[������������_����� + 1];
                                int s=0;
								for(int l=�������_�������;l!=-2;l=��������[l])
								{
                                    ����[s] = l;
                                    s++;
								}
                                ����[s] = �������_�������;
							}
                            ���������_�������++;
                    }
                    else //������ �� �������
                    {
                            // ��� �����
                            ��������[�������_�������]=-1;
                            ���������_�������=�������_�������+1;
                            if(�������_�������==c&&�������[�������_�����-1]==b||�������_�������==b&&�������[�������_�����-1]==c)
								�����_��������=false;
							�������_�������=�������[--�������_�����];
                    }
            }
            while (�������_�����>0);
            if (������������_����� == 0) return false;
            for (int l = 0; l < ������������_�����; l++)
                �����.����������������(����[l], ����[l+1]);
            return true;
    }
}