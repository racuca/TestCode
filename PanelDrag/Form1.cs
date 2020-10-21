using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PanelDrag
{
    public partial class Form1 : Form
    {

        int CountR, CountC, CountT = 0;
        List<Panel> panelR = new List<Panel>();
        List<Panel> panelC = new List<Panel>();
        List<Panel> panelT = new List<Panel>();

        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }



        private void Button1_Click(object sender, EventArgs e)
        {
            panelR.Add(new Panel());

            if (CountR == 0)
            {
                panelR[0].Location = new Point(5, 5);
            }

            else if (CountR >= 1)
            {
                panelR.Last().Location = new Point(panelR[CountR - 1].Location.X + 100, panelR[CountR - 1].Location.Y);  //last로 바꿔보기
            }

            panelR[CountR].Size = new Size(70, 40);
            panelR[CountR].Name = "panelR" + CountR.ToString();
            this.Controls.Add(panelR[CountR]);

            Graphics graphics = panelR[CountR].CreateGraphics();
            SolidBrush RedBrush = new SolidBrush(Color.Red);
            graphics.FillRectangle(RedBrush, 0, 0, 70, 40);

            Label labelR = new Label();
            labelR.Text = "R" + CountR.ToString();
            labelR.AutoSize = true;
            labelR.Location = new Point(15, 10);
            labelR.BackColor = Color.Red;
            labelR.Font = new Font(labelR.Font.FontFamily, labelR.Font.Size + 5);
            panelR[CountR].Controls.Add(labelR);

            CountR++;
        }

        bool mousemove = false;

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Point p = e.Location;
            mousemove = true;
        }
        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            mousemove = false;
        }


        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (mousemove == true)
                panelR[CountR].Location = e.Location;
        }
    }
}
