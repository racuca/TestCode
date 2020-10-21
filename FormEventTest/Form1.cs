using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FormEventTest
{
    public partial class Form1 : Form
    {

        delegate void MyDelegate(string msg);
        event MyDelegate MyHandler;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button1.Click += Button1_Click;
            button1.Click += Button1_Click1;
            button1.Click += Button1_Click2;

            MyHandler += Form1_MyHandler;
        }

        private void Form1_MyHandler(string msg)
        {
            MessageBox.Show(msg);
        }

        private void Button1_Click2(object sender, EventArgs e)
        {
            Console.WriteLine("Click2");
        }

        private void Button1_Click1(object sender, EventArgs e)
        {
            Console.WriteLine("Click1");
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Console.WriteLine("Click");

            if (MyHandler != null)
            {
                MyHandler("버튼을 클릭하였습니다.");
            }
        }
    }
}
