using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Graph_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_paint(object sender, PaintEventArgs e)
        {
            var Nodes = 4;
            var edges = 5;
            Graphics l = e.Graphics;
            Pen p = new Pen(Color.Black, 2);
            l.DrawEllipse(p, 50,50, 50, 50);
            l.DrawLine(p, 70 , 35, 150, 60);
            l.Dispose();
        }
    }
}
