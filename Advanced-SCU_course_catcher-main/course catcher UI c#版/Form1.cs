using System.Windows.Forms;
using System.Diagnostics;//����shell
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
        public static string TextGainCenter(string text, string left, string right)//ȡ���м��ı�
        {
            //�ж��Ƿ�Ϊnull������empty
            if (string.IsNullOrEmpty(left))
                return "";
            if (string.IsNullOrEmpty(right))
                return "";
            if (string.IsNullOrEmpty(text))
                return "";
            //�ж��Ƿ�Ϊnull������empty
            int Lindex = text.IndexOf(left); //����left��λ��
            if (Lindex == -1)
            { //�ж��Ƿ��ҵ�left
                return "";
            }
            Lindex = Lindex + left.Length; //ȡ��left�ұ��ı���ʼλ��
            int Rindex = text.IndexOf(right, Lindex);//��left���ұ߿�ʼѰ��right
            if (Rindex == -1)
            {//�ж��Ƿ��ҵ�right
                return "";
            }
            return text.Substring(Lindex, Rindex - Lindex);//���ز��ҵ����ı�
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
            button_add.Text = "<-���������ѡ��";
        }

        private void button_b_Click(object sender, EventArgs e)
        {
            button_a.ForeColor = Color.FromName("ControlText");
            button_b.ForeColor = Color.FromName("Highlight");
            listBox_courselist1.Visible = false;
            listBox_courselist2.Visible = true;
            index = 2;
            button_add.Text = "<-���������ѡ��";
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
                MessageBox.Show("����ȷ����γ̺źͿ���ţ�", "warm:");
                return;
            }
            if (textBox_course2.Text.Length != 2)
            {
                MessageBox.Show("�����Ϊ��λ������01", "warm:");
                return;
            }
            string willAdd = textBox_course1.Text + "_" + textBox_course2.Text;
            if (index == 1)
            {
                for (int i = 0; i < listBox_courselist1.Items.Count; i++)
                {
                    if (listBox_courselist1.Items[i].ToString() == willAdd)
                    {
                        MessageBox.Show("�ظ���ӣ�", "warm:");
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
                        MessageBox.Show("�ظ���ӣ�", "warm:");
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
            MessageBox.Show("д����ɣ�������main�������Σ���ȷ���Ѱ�װpython������", "notice:");
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
            cmd = cmd.Trim().TrimEnd('&') + "&exit";//˵�������������Ƿ�ɹ���ִ��exit������򵱵���ReadToEnd()����ʱ���ᴦ�ڼ���״̬
            using (Process p = new Process())
            {
                p.StartInfo.FileName = CmdPath;
                p.StartInfo.UseShellExecute = false; //�Ƿ�ʹ�ò���ϵͳshell����
                p.StartInfo.RedirectStandardInput = true; //�������Ե��ó����������Ϣ
                p.StartInfo.RedirectStandardOutput = true; //�ɵ��ó����ȡ�����Ϣ
                p.StartInfo.RedirectStandardError = true; //�ض����׼�������
                p.StartInfo.CreateNoWindow = true; //����ʾ���򴰿�
                p.Start();//��������

                //��cmd����д������
                p.StandardInput.WriteLine(cmd);
                p.StandardInput.AutoFlush = true;

                //��ȡcmd���ڵ������Ϣ
                string output = p.StandardOutput.ReadToEnd();
                p.WaitForExit();//�ȴ�����ִ�����˳�����
                p.Close();

                return output;
            }
        }
    }
}