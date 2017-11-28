using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace WindowsLEDApp
{
    public partial class StartupScreen : Form
    {
        public StartupScreen()
        {
            InitializeComponent();
            var comList = new List<ComPort>();

            foreach (string comName in SerialPort.GetPortNames())
            {
                comList.Add(new ComPort { Name = comName.ToLower(), Value = comName });
            }

            ComportSelector.DataSource = comList;
            ComportSelector.DisplayMember = "Name";
            ComportSelector.ValueMember = "Value";
            ComportSelector.DropDownStyle = ComboBoxStyle.DropDownList;

            ComPortButton.Click += new System.EventHandler(ComportButton_Click);
            void ComportButton_Click(object sender, EventArgs e)
            {
                ComPort comport = (ComPort)ComportSelector.SelectedItem;

                SerialPort serial = new SerialPort();
                serial.BaudRate = 4800;
                serial.PortName = comport.Value;
                serial.Open();
            }
        }
    }
}
