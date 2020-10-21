using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;

namespace WPFElementControl
{
    public class MoveThumb : Thumb
    {
        public MoveThumb()
        {
            DragDelta += new DragDeltaEventHandler(MoveThumb_DragDelta);
        }

        private void MoveThumb_DragDelta(object sender, DragDeltaEventArgs e)
        {
            Control designeritem = this.DataContext as Control;

            if (designeritem == null)
                return;

            double left = Canvas.GetLeft(designeritem);
            double top = Canvas.GetTop(designeritem);

            Canvas.SetLeft(designeritem, left + e.HorizontalChange);
            Canvas.SetTop(designeritem, top + e.VerticalChange);
        }
    }
}
