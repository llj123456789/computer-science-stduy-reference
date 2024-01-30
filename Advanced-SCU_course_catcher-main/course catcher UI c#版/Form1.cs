using System.Windows.Forms;
using System.Diagnostics;//运行shell
using System.IO;
using static System.Windows.Forms.LinkLabel;

namespace course_catcher_UI
{

    public partial class Form1 : Form
    {
        public string userdataText;
        public string ID;
        public string password;
        public int index = 1;
        public static string TextGainCenter(string text, string left, string right)//取出中间文本
        {
            //判断是否为null或者是empty
            if (string.IsNullOrEmpty(left))
                return "";
            if (string.IsNullOrEmpty(right))
                return "";
            if (string.IsNullOrEmpty(text))
                return "";
            //判断是否为null或者是empty
            int Lindex = text.IndexOf(left); //搜索left的位置
            if (Lindex == -1)
            { //判断是否找到left
                return "";
            }
            Lindex = Lindex + left.Length; //取出left右边文本起始位置
            int Rindex = text.IndexOf(right, Lindex);//从left的右边开始寻找right
            if (Rindex == -1)
            {//判断是否找到right
                return "";
            }
            return text.Substring(Lindex, Rindex - Lindex);//返回查找到的文本
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void button_a_Click(object sender, EventArgs e)
        {
            button_b.ForeColor = Color.FromName("ControlText");
            button_a.ForeColor = Color.FromName("Highlight");
            listBox_courselist1.Visible = true;
            listBox_courselist2.Visible = false;
            index = 1;
            button_add.Text = "<-添加至方案选课";
        }

        private void button_b_Click(object sender, EventArgs e)
        {
            button_a.ForeColor = Color.FromName("ControlText");
            button_b.ForeColor = Color.FromName("Highlight");
            listBox_courselist1.Visible = false;
            listBox_courselist2.Visible = true;
            index = 2;
            button_add.Text = "<-添加至自由选课";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (File.Exists(@".\user_data.json"))
            {
                userdataText = File.ReadAllText(@".\user_data.json");
            }
            else
            {
                return;
            }
            ID = TextGainCenter(userdataText, "std_id\"" + ": \"", "\"");
            password = TextGainCenter(userdataText, "password\": \"", "\"");
            textBox_ID.Text = ID;
            textBox_password.Text = password;
            string courseAtext = TextGainCenter(userdataText, "a\": [", "]");
            string courseBtext = TextGainCenter(userdataText, "b\": [", "]");
            string[] courseA = courseAtext.Split("}, {");
            string[] courseB = courseBtext.Split("}, {");
            foreach (string s in courseA)
            {
                if(s!="")
                listBox_courselist1.Items.Add(TextGainCenter(s, "course_id\": \"", "\"") + "_" + TextGainCenter(s, "course_index\": \"", "\""));
            }
            foreach (string s in courseB)
            {
                if(s!="")
                listBox_courselist2.Items.Add(TextGainCenter(s, "course_id\": \"", "\"") + "_" + TextGainCenter(s, "course_index\": \"", "\""));
            }
        }

        private void button_delete_Click(object sender, EventArgs e)
        {
            if (index == 1)
            {
                if (listBox_courselist1.SelectedItem != null)
                    listBox_courselist1.Items.Remove(listBox_courselist1.SelectedItem);
                if (listBox_courselist1.Items.Count == 0)
                    return;
            }
            else
            {
                if (listBox_courselist2.SelectedItem != null)
                    listBox_courselist2.Items.Remove(listBox_courselist2.SelectedItem);
                if (listBox_courselist2.Items.Count == 0)
                    return;
            }
        }

        private void button_add_Click(object sender, EventArgs e)
        {
            if (textBox_course1.Text == "" || textBox_course2.Text == "")
            {
                MessageBox.Show("请正确输入课程号和课序号！", "warm:");
                return;
            }
            if (textBox_course2.Text.Length != 2)
            {
                MessageBox.Show("课序号为两位数，如01", "warm:");
                return;
            }
            string willAdd = textBox_course1.Text + "_" + textBox_course2.Text;
            if (index == 1)
            {
                for (int i = 0; i < listBox_courselist1.Items.Count; i++)
                {
                    if (listBox_courselist1.Items[i].ToString() == willAdd)
                    {
                        MessageBox.Show("重复添加！", "warm:");
                        return;
                    }
                }
                listBox_courselist1.Items.Add(willAdd);
                textBox_course1.Text = "";
                textBox_course2.Text = "";
            }
            else
            {
                for (int i = 0; i < listBox_courselist2.Items.Count; i++)
                {
                    if (listBox_courselist2.Items[i].ToString() == willAdd)
                    {
                        MessageBox.Show("重复添加！", "warm:");
                        return;
                    }
                }
                listBox_courselist2.Items.Add(willAdd);
                textBox_course2.Text = "";
                textBox_course1.Text = "";
            }
        }

        private void button_OK_Click(object sender, EventArgs e)
        {
            ID=textBox_ID.Text;
            password=textBox_password.Text;
            string newStudata;
            newStudata = "{\"std_id\": \"" + ID + "\", \"password\": \"" + password + "\", \"course\": {\"a\": [";
            if(listBox_courselist1.Items.Count!=0)
            {
                for(int i=0;i<listBox_courselist1 .Items.Count;i++)
                {
                    string tmp = listBox_courselist1.Items[i].ToString();
                    newStudata += "{\"course_id\": \"" + tmp.Substring(0, tmp.IndexOf("_")) + "\", \"course_index\": \"" + tmp.Substring(tmp.Length - 2, 2) + "\"}";
                    if(i!=listBox_courselist1.Items.Count-1)
                    {
                        newStudata += ", ";
                    }
                }
            }
            newStudata += "], \"b\": [";
            if (listBox_courselist2.Items.Count != 0)
            {
                for (int i = 0; i < listBox_courselist2.Items.Count; i++)
                {
                    string tmp = listBox_courselist2.Items[i].ToString();
                    newStudata += "{\"course_id\": \"" + tmp.Substring(0, tmp.IndexOf("_")) + "\", \"course_index\": \"" + tmp.Substring(tmp.Length - 2, 2) + "\"}";
                    if (i != listBox_courselist2.Items.Count - 1)
                    {
                        newStudata += ", ";
                    }
                }
            }
            newStudata += "]}}";
            System.IO.File.WriteAllText(@".\user_data.json", newStudata);
            MessageBox.Show("写入完成，即将打开main程序抢课，请确保已安装python环境！", "notice:");
            string outtext = cmd.Cmd.RunCmd("py ./main.py");
            MessageBox.Show(outtext, "message:");
        }
    }
}

namespace cmd
{
    class Cmd
    {
        private static string CmdPath = @"C:\Windows\System32\cmd.exe";
        public static string RunCmd(string cmd)
        {
            cmd = cmd.Trim().TrimEnd('&') + "&exit";//说明：不管命令是否成功均执行exit命令，否则当调用ReadToEnd()方法时，会处于假死状态
            using (Process p = new Process())
            {
                p.StartInfo.FileName = CmdPath;
                p.StartInfo.UseShellExecute = false; //是否使用操作系统shell启动
                p.StartInfo.RedirectStandardInput = true; //接受来自调用程序的输入信息
                p.StartInfo.RedirectStandardOutput = true; //由调用程序获取输出信息
                p.StartInfo.RedirectStandardError = true; //重定向标准错误输出
                p.StartInfo.CreateNoWindow = true; //不显示程序窗口
                p.Start();//启动程序

                //向cmd窗口写入命令
                p.StandardInput.WriteLine(cmd);
                p.StandardInput.AutoFlush = true;

                //获取cmd窗口的输出信息
                string output = p.StandardOutput.ReadToEnd();
                p.WaitForExit();//等待程序执行完退出进程
                p.Close();

                return output;
            }
        }
    }
}