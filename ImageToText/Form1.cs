using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ImageToText
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "png file|*.png|Image Files|*.*";
            DialogResult r = ofd.ShowDialog();
            if (r != DialogResult.OK)
            {
                return;
            }
            string filename = ofd.FileName;

            byte[] data = File.ReadAllBytes(filename);
            string text = Convert.ToBase64String(data);

            textBox2.Text = text;
        }
    }
}
