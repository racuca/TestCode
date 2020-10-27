using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace ImageToText
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Image <=> Data URI Text v " + this.ProductVersion;
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "png file|*.png";
            DialogResult r = ofd.ShowDialog();
            if (r != DialogResult.OK)
            {
                return;
            }
            string filename = ofd.FileName;
            textBox1.Text = filename;

            byte[] data = File.ReadAllBytes(filename);
            string text = Convert.ToBase64String(data);

            textBox2.Text = text;
        }

        private void btnConvertToImage_Click(object sender, EventArgs e)
        {
            string data = @"data:image/png;base64," + textBox2.Text;

            var base64Data = Regex.Match(data, @"data:image/(?<type>.+?),(?<data>.+)").Groups["data"].Value;
            var binData = Convert.FromBase64String(base64Data);

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.AddExtension = true;
            sfd.DefaultExt = ".png";
            DialogResult r = sfd.ShowDialog();
            if (r != DialogResult.OK)
                return;

            string filename = sfd.FileName;

            try
            {
                using (var stream = new MemoryStream(binData))
                {
                    Bitmap Image = new Bitmap(stream);
                    Image.Save(filename, ImageFormat.Png);
                    MessageBox.Show("정상적으로 저장되었습니다.");
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("오류가 발생하였습니다. ");
            }
        }

    }
}
