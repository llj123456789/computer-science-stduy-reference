namespace course_catcher_UI
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            folderBrowserDialog1 = new FolderBrowserDialog();
            button_a = new Button();
            button_b = new Button();
            listBox_courselist1 = new ListBox();
            label_ID = new Label();
            label_password = new Label();
            textBox_ID = new TextBox();
            textBox_password = new TextBox();
            groupBox_courseSelect = new GroupBox();
            button_OK = new Button();
            button_add = new Button();
            textBox_course2 = new TextBox();
            textBox_course1 = new TextBox();
            label_course2 = new Label();
            label_course1 = new Label();
            button_delete = new Button();
            listBox_courselist2 = new ListBox();
            groupBox_courseSelect.SuspendLayout();
            SuspendLayout();
            // 
            // button_a
            // 
            button_a.ForeColor = SystemColors.Highlight;
            button_a.Location = new Point(1, 1);
            button_a.Name = "button_a";
            button_a.Size = new Size(93, 34);
            button_a.TabIndex = 0;
            button_a.Text = "方案选课";
            button_a.UseVisualStyleBackColor = true;
            button_a.Click += button_a_Click;
            // 
            // button_b
            // 
            button_b.Location = new Point(100, 1);
            button_b.Name = "button_b";
            button_b.Size = new Size(93, 34);
            button_b.TabIndex = 1;
            button_b.Text = "自由选课";
            button_b.UseVisualStyleBackColor = true;
            button_b.Click += button_b_Click;
            // 
            // listBox_courselist1
            // 
            listBox_courselist1.FormattingEnabled = true;
            listBox_courselist1.ItemHeight = 24;
            listBox_courselist1.Location = new Point(1, 29);
            listBox_courselist1.Name = "listBox_courselist1";
            listBox_courselist1.Size = new Size(372, 580);
            listBox_courselist1.TabIndex = 2;
            // 
            // label_ID
            // 
            label_ID.AutoSize = true;
            label_ID.Location = new Point(488, 71);
            label_ID.Name = "label_ID";
            label_ID.Size = new Size(64, 24);
            label_ID.TabIndex = 3;
            label_ID.Text = "学号：";
            // 
            // label_password
            // 
            label_password.AutoSize = true;
            label_password.Location = new Point(488, 123);
            label_password.Name = "label_password";
            label_password.Size = new Size(64, 24);
            label_password.TabIndex = 4;
            label_password.Text = "密码：";
            // 
            // textBox_ID
            // 
            textBox_ID.Font = new Font("Microsoft YaHei UI", 10.5F);
            textBox_ID.Location = new Point(552, 71);
            textBox_ID.MaxLength = 13;
            textBox_ID.Name = "textBox_ID";
            textBox_ID.Size = new Size(290, 34);
            textBox_ID.TabIndex = 5;
            textBox_ID.WordWrap = false;
            // 
            // textBox_password
            // 
            textBox_password.Font = new Font("Microsoft YaHei UI", 10.5F);
            textBox_password.Location = new Point(552, 117);
            textBox_password.Name = "textBox_password";
            textBox_password.Size = new Size(290, 34);
            textBox_password.TabIndex = 6;
            textBox_password.WordWrap = false;
            // 
            // groupBox_courseSelect
            // 
            groupBox_courseSelect.Controls.Add(button_OK);
            groupBox_courseSelect.Controls.Add(button_add);
            groupBox_courseSelect.Controls.Add(textBox_course2);
            groupBox_courseSelect.Controls.Add(textBox_course1);
            groupBox_courseSelect.Controls.Add(label_course2);
            groupBox_courseSelect.Controls.Add(label_course1);
            groupBox_courseSelect.Location = new Point(443, 211);
            groupBox_courseSelect.Name = "groupBox_courseSelect";
            groupBox_courseSelect.Size = new Size(455, 426);
            groupBox_courseSelect.TabIndex = 7;
            groupBox_courseSelect.TabStop = false;
            groupBox_courseSelect.Text = "选课";
            // 
            // button_OK
            // 
            button_OK.Font = new Font("幼圆", 12F, FontStyle.Regular, GraphicsUnit.Point, 134);
            button_OK.ForeColor = Color.OrangeRed;
            button_OK.Location = new Point(134, 286);
            button_OK.Name = "button_OK";
            button_OK.Size = new Size(242, 76);
            button_OK.TabIndex = 5;
            button_OK.Text = "完成选课，点击保存起洞！";
            button_OK.UseVisualStyleBackColor = true;
            button_OK.Click += button_OK_Click;
            // 
            // button_add
            // 
            button_add.Font = new Font("Microsoft YaHei UI", 10.5F, FontStyle.Regular, GraphicsUnit.Point, 134);
            button_add.ForeColor = SystemColors.Highlight;
            button_add.Location = new Point(163, 180);
            button_add.Name = "button_add";
            button_add.Size = new Size(193, 57);
            button_add.TabIndex = 4;
            button_add.Text = "<-添加至方案选课";
            button_add.UseVisualStyleBackColor = true;
            button_add.Click += button_add_Click;
            // 
            // textBox_course2
            // 
            textBox_course2.Location = new Point(163, 111);
            textBox_course2.MaxLength = 2;
            textBox_course2.Name = "textBox_course2";
            textBox_course2.Size = new Size(236, 30);
            textBox_course2.TabIndex = 3;
            // 
            // textBox_course1
            // 
            textBox_course1.Location = new Point(163, 69);
            textBox_course1.MaxLength = 20;
            textBox_course1.Name = "textBox_course1";
            textBox_course1.Size = new Size(236, 30);
            textBox_course1.TabIndex = 2;
            // 
            // label_course2
            // 
            label_course2.AutoSize = true;
            label_course2.Location = new Point(92, 111);
            label_course2.Name = "label_course2";
            label_course2.Size = new Size(64, 24);
            label_course2.TabIndex = 1;
            label_course2.Text = "课序号";
            // 
            // label_course1
            // 
            label_course1.AutoSize = true;
            label_course1.Location = new Point(93, 72);
            label_course1.Name = "label_course1";
            label_course1.Size = new Size(64, 24);
            label_course1.TabIndex = 0;
            label_course1.Text = "课程号";
            // 
            // button_delete
            // 
            button_delete.Location = new Point(1, 613);
            button_delete.Name = "button_delete";
            button_delete.Size = new Size(372, 34);
            button_delete.TabIndex = 8;
            button_delete.Text = "删除选中";
            button_delete.UseVisualStyleBackColor = true;
            button_delete.Click += button_delete_Click;
            // 
            // listBox_courselist2
            // 
            listBox_courselist2.FormattingEnabled = true;
            listBox_courselist2.ItemHeight = 24;
            listBox_courselist2.Location = new Point(1, 29);
            listBox_courselist2.Name = "listBox_courselist2";
            listBox_courselist2.Size = new Size(372, 580);
            listBox_courselist2.TabIndex = 2;
            listBox_courselist2.Visible = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(11F, 24F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(910, 649);
            Controls.Add(button_delete);
            Controls.Add(groupBox_courseSelect);
            Controls.Add(textBox_password);
            Controls.Add(textBox_ID);
            Controls.Add(label_password);
            Controls.Add(label_ID);
            Controls.Add(listBox_courselist2);
            Controls.Add(listBox_courselist1);
            Controls.Add(button_b);
            Controls.Add(button_a);
            FormBorderStyle = FormBorderStyle.FixedDialog;
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            groupBox_courseSelect.ResumeLayout(false);
            groupBox_courseSelect.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private FolderBrowserDialog folderBrowserDialog1;
        private Button button_a;
        private Button button_b;
        private ListBox listBox_courselist1;
        private Label label_ID;
        private Label label_password;
        private TextBox textBox_ID;
        private TextBox textBox_password;
        private GroupBox groupBox_courseSelect;
        private TextBox textBox_course2;
        private TextBox textBox_course1;
        private Label label_course2;
        private Label label_course1;
        private Button button_delete;
        private Button button_OK;
        private Button button_add;
        private ListBox listBox_courselist2;
    }
}
