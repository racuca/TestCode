using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //List<string> a = new List<string> { "A", "A", "A", "B", "C" };
            //int id = a.IndexOf("A");
            //var b = a.Select(i => a[id]);
            //var c = a.Except(b);

            //a.RemoveAll(i => i == a[id]);

            //Form form = new Form();
            //form.MdiParent = this;
            //form.Show();

            //RegisterHotKey(this.Handle, WM_HOTKEY, KeyModifiers.Alt, Keys.W);

        }

        [DllImport("user32.dll")]
        public static extern bool RegisterHotKey(IntPtr hWnd, int id, KeyModifiers fsModifiers, Keys vk);

        [DllImport("user32.dll")]
        public static extern bool UnregisterHotKey(IntPtr hWnd, int id);

        const int HOTKEY_ID = 31197; //Any number to use to identify the hotkey instance

        public enum KeyModifiers
        {
            None = 0,
            Alt = 1,
            Control = 2,
            Shift = 4,
            Windows = 8
        }

        const int WM_HOTKEY = 0x0312;
        protected override void WndProc(ref Message message)
        {
            switch (message.Msg)
            {
                case WM_HOTKEY:
                    Keys key = (Keys)(((int)message.LParam >> 16) & 0xFFFF);
                    KeyModifiers modifier = (KeyModifiers)((int)message.LParam & 0xFFFF);
                    //MessageBox.Show("HotKey Pressed :" + modifier.ToString() + " " + key.ToString());

                    if ((KeyModifiers.Control | KeyModifiers.Shift) == modifier && Keys.N == key)
                    {
                        Process.Start("notepad.exe");
                    }

                    break;
            }
            base.WndProc(ref message);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 핫키 등록
            RegisterHotKey(this.Handle, HOTKEY_ID, KeyModifiers.Control | KeyModifiers.Shift, Keys.N);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //핫키 해제
            UnregisterHotKey(this.Handle, HOTKEY_ID);
        }

    }
}
