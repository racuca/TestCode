using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace WindowsFormsApp1
{
    public enum ConfigEnum {
        a, 
        b, 
        title, 
        truefalse
    }

    public class configfile
    {
        /// 값 변수
        public int a = 0;
        public int b = 1;
        public string title = "config";
        public bool truefalse = true;
        public string filename;


        public int A
        {
            set { a = value; update(ConfigEnum.a, a.ToString()); }
        }

        Dictionary<string, string> configdatas = new Dictionary<string, string>();
               

        private void update(ConfigEnum e, string a)
        {
            configdatas[e.ToString()] = a;
        }

        public configfile()
        {
            filename = "c:\app\\config\\config.ini";
        }

        public void read()
        {
            string[] lines = File.ReadAllLines(filename);

            foreach (string line in lines)
            {
                string[] data = line.Split('=');
                configdatas.Add(data[0].Trim(), data[1].Trim());
            }
        }

        public void write()
        {
            File.Delete(filename);
            string[] configdataarray = { a.ToString(), b.ToString(), title, truefalse.ToString() };
            foreach (ConfigEnum e in Enum.GetValues(typeof(ConfigEnum)))
            {
                File.AppendAllText(filename, e.ToString() + " = " + configdataarray[(int)e]);
            }
        }
    }
}
