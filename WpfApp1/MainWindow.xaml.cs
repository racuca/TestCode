using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        DataTable dt;
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            dt = new DataTable();

            dt.Columns.Add("NO");
            dt.Columns.Add("NAME");
            dt.Columns.Add("HOBBY");
            dt.Columns.Add("ADDRESS");

            dt.Rows.Add(new String[] { "1", "홍길동", "등산", "서울시 마포구 마포아파트" });
            dt.Rows.Add(new String[] { "2", "김무개", "족구", "경기도 성남시 상대원동" });

            dataGrid.ItemsSource = dt.DefaultView;

        }

        private void AddrChangeButton_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(dt.Rows[dataGrid.SelectedIndex]["ADDRESS"].ToString());

        }
    }
}
