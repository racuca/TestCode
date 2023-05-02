using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            string a = "AAAA,BBBB,CCCC,DDDD,EEEE,FFFF,GGGG,HHHH,IIII";

            var result = a.Select((b, i) => b.Equals(',') ? i : -1).Where(i => i != -1 && i != 0);

            Console.WriteLine("Total comma indexes : ");
            for (int i = 0; i < result.Count(); i++)
            {
                Console.Write(result.ElementAt(i) + " ");
            }

            Console.WriteLine("\ntarget comma indexes : ");
            for (int i = result.Count() - 1; i >= 0; i--)
            {
                if (i != 0 && i % 2 == 1)
                {
                    Console.WriteLine(result.ElementAt(i));
                    a = a.Remove(result.ElementAt(i), 1).Insert(result.ElementAt(i), "@@");
                }
            }

            Console.WriteLine(a);
        }
    }
}
