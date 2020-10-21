using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;

namespace WPFElementControl
{
    public class ResizeThumb : Thumb
    {
        public ResizeThumb()
        {
            DragDelta += new DragDeltaEventHandler(ResizeThumb_DragDelta);
        }

        private void ResizeThumb_DragDelta(object sender, DragDeltaEventArgs e)
        {
            Control designeritem = this.DataContext as Control;

            if (designeritem == null)
                return;

            double deltaVertical, deltaHorizontal;

            switch (VerticalAlignment)
            {
                case VerticalAlignment.Bottom:
                    deltaVertical = Math.Min(-e.VerticalChange, designeritem.ActualHeight - designeritem.MinHeight);
                    designeritem.Height -= deltaVertical;
                    break;
                case VerticalAlignment.Top:
                    deltaVertical = Math.Min(e.VerticalChange, designeritem.ActualHeight - designeritem.MinHeight);
                    Canvas.SetTop(designeritem, Canvas.GetTop(designeritem) + deltaVertical);
                    designeritem.Height -= deltaVertical;
                    break;
                default:
                    break;
            }

            switch (HorizontalAlignment)
            {
                case HorizontalAlignment.Left:
                    deltaHorizontal = Math.Min(e.HorizontalChange, designeritem.ActualWidth - designeritem.MinWidth);
                    Canvas.SetLeft(designeritem, Canvas.GetLeft(designeritem) + deltaHorizontal);
                    designeritem.Width -= deltaHorizontal;
                    break;
                case HorizontalAlignment.Right:
                    deltaHorizontal = Math.Min(-e.HorizontalChange, designeritem.ActualWidth - designeritem.MinWidth);
                    designeritem.Width -= deltaHorizontal;
                    break;
                default:
                    break;
            }

            e.Handled = true;

        }
    }
}
