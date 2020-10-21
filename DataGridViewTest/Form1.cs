using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DataGridViewTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.AutoGenerateColumns = false;

            DataTable dt = new DataTable();
            dt.Columns.Add("Name", typeof(String));
            dt.Columns.Add("Money", typeof(String));
            dt.Rows.Add(new object[] { "Hi", 100 });
            dt.Rows.Add(new object[] { "Ki", 30 });

            DataGridViewComboBoxColumn money = new DataGridViewComboBoxColumn();
            var list11 = new List<string>() { "10", "30", "80", "100" };
            money.DataSource = list11;
            money.HeaderText = "Money";
            money.DataPropertyName = "Money";

            DataGridViewTextBoxColumn name = new DataGridViewTextBoxColumn();
            name.HeaderText = "Name";
            name.DataPropertyName = "Name";

            dataGridView1.DataSource = dt;
            dataGridView1.Columns.AddRange(name, money);
        }
    }
}
