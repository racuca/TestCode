using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;

namespace WPFElementControl
{
    public class SimpleCircleAdorner : Adorner
    {
        Control child;


        // Be sure to call the base class constructor.
        public SimpleCircleAdorner(Control adornedElement, Panel ownerPanel) : base(adornedElement)
        {
            child = adornedElement;
            _ownerPanel = ownerPanel;
        }

        protected override void OnMouseEnter(MouseEventArgs e)
        {
            Point point = Mouse.GetPosition(AdornedElement);
            _currentPosition = getMousePosition(point);
            switch (_currentPosition)
            {
                case MousePosition.BR:
                case MousePosition.TL:
                    Cursor = Cursors.SizeNWSE;
                    break;
                case MousePosition.BL:
                case MousePosition.TR:
                    Cursor = Cursors.SizeNESW;
                    break;
            }
        }

        protected override void OnMouseLeave(MouseEventArgs e)
        {
            //AdornerLayer adornerLayer = AdornerLayer.GetAdornerLayer(AdornedElement);
            //if (adornerLayer != null)
            //{
            //    Adorner[] adorners = adornerLayer.GetAdorners(AdornedElement);
            //    if (adorners != null)
            //    {
            //        foreach (Adorner adorner in adorners)
            //        {
            //            adornerLayer.Remove(adorner);
            //        }
            //    }
            //}
        }

        MousePosition _currentPosition;
        Panel _ownerPanel;
        bool _isDraging = false;
        Point _startPosition;

        protected override void OnPreviewMouseLeftButtonDown(MouseButtonEventArgs e)
        {
            if (Mouse.Capture(this))
            {
                _isDraging = true;
                _startPosition = Mouse.GetPosition(_ownerPanel);
            }
        }

        protected override void OnPreviewMouseMove(MouseEventArgs e)
        {
            if (_isDraging)
            {
                Point newPosition = Mouse.GetPosition(_ownerPanel);
                double diffX = (newPosition.X - _startPosition.X);
                double diffY = (newPosition.Y - _startPosition.Y);

                Control ui = child;

                // we should decide whether to change Width and Height or to change Canvas.Left and Canvas.Right
                if (Math.Abs(diffX) >= 1 || Math.Abs(diffY) >= 1)
                {
                    switch (_currentPosition)
                    {
                        case MousePosition.TL:
                        case MousePosition.BL:
                            Canvas.SetLeft(ui, Math.Max(0, Canvas.GetLeft(ui) + diffX));
                            ui.Width = Math.Max(0, ui.Width - diffX);
                            _ownerPanel.InvalidateArrange();
                            break;
                        case MousePosition.BR:
                        case MousePosition.TR:
                            ui.Width = Math.Max(0, ui.Width + diffX);
                            break;
                    }

                    switch (_currentPosition)
                    {
                        case MousePosition.TL:
                        case MousePosition.TR:
                            Canvas.SetTop(ui, Math.Max(0, Canvas.GetTop(ui) + diffY));
                            ui.Height = Math.Max(0, ui.Height - diffY);
                            break;
                        case MousePosition.BL:
                        case MousePosition.BR:
                            ui.Height = Math.Max(0, ui.Height + diffY);
                            break;

                    }
                }
                _startPosition = newPosition;
            }
        }

        protected override void OnPreviewMouseLeftButtonUp(MouseButtonEventArgs e)
        {

        }

        protected override void OnPreviewMouseRightButtonUp(MouseButtonEventArgs e)
        {
            if (_isDraging)
            {
                Mouse.Capture(null);
                _isDraging = false;
            }
        }

        MousePosition getMousePosition(Point point) // point relative to element
        {
            double h2 = ActualHeight / 2;
            double w2 = ActualWidth / 2;
            if (point.X < w2 && point.Y < h2)
                return MousePosition.TL;
            else if (point.X > w2 && point.Y > h2)
                return MousePosition.BR;
            else if (point.X > w2 && point.Y < h2)
                return MousePosition.TR;
            else
                return MousePosition.BL;
        }

        enum MousePosition
        {
            TL,
            TR,
            BL,
            BR
        }

        // A common way to implement an adorner's rendering behavior is to override the OnRender
        // method, which is called by the layout system as part of a rendering pass.
        protected override void OnRender(DrawingContext drawingContext)
        {
            base.OnRender(drawingContext);

            Rect adornedElementRect = new Rect(this.AdornedElement.DesiredSize);

            // Some arbitrary drawing implements.
            SolidColorBrush renderBrush = new SolidColorBrush(Colors.Green);
            renderBrush.Opacity = 0.2;
            Pen renderPen = new Pen(new SolidColorBrush(Colors.Navy), 1.5);
            double renderRadius = 5.0;

            // Draw a circle at each corner.
            drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopLeft, renderRadius, renderRadius);
            drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.TopRight, renderRadius, renderRadius);
            drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomLeft, renderRadius, renderRadius);
            drawingContext.DrawEllipse(renderBrush, renderPen, adornedElementRect.BottomRight, renderRadius, renderRadius);
        }


    }
}
