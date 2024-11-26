namespace RGZ
{
    partial class RGZ
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.teachersButton = new System.Windows.Forms.Button();
            this.disciplinesButton = new System.Windows.Forms.Button();
            this.departmentDisciplinesButton = new System.Windows.Forms.Button();
            this.teachersOfDisciplineButton = new System.Windows.Forms.Button();
            this.teacherReferenceButton = new System.Windows.Forms.Button();
            this.teacherIdTextBox = new System.Windows.Forms.TextBox();
            this.disciplineIdTextBox = new System.Windows.Forms.TextBox();
            this.updateTableButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView
            // 
            this.dataGridView.BackgroundColor = System.Drawing.Color.White;
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Location = new System.Drawing.Point(185, 21);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.Size = new System.Drawing.Size(603, 326);
            this.dataGridView.TabIndex = 0;
            // 
            // teachersButton
            // 
            this.teachersButton.BackColor = System.Drawing.Color.Aqua;
            this.teachersButton.Location = new System.Drawing.Point(18, 21);
            this.teachersButton.Name = "teachersButton";
            this.teachersButton.Size = new System.Drawing.Size(150, 23);
            this.teachersButton.TabIndex = 1;
            this.teachersButton.Text = "Преподаватели";
            this.teachersButton.UseVisualStyleBackColor = false;
            this.teachersButton.Click += new System.EventHandler(this.TeachersButtonClick);
            // 
            // disciplinesButton
            // 
            this.disciplinesButton.BackColor = System.Drawing.Color.Aqua;
            this.disciplinesButton.Location = new System.Drawing.Point(18, 63);
            this.disciplinesButton.Name = "disciplinesButton";
            this.disciplinesButton.Size = new System.Drawing.Size(150, 23);
            this.disciplinesButton.TabIndex = 2;
            this.disciplinesButton.Text = "Дисциплины";
            this.disciplinesButton.UseVisualStyleBackColor = false;
            this.disciplinesButton.Click += new System.EventHandler(this.DisciplinesButtonClick);
            // 
            // departmentDisciplinesButton
            // 
            this.departmentDisciplinesButton.BackColor = System.Drawing.Color.Aqua;
            this.departmentDisciplinesButton.Location = new System.Drawing.Point(18, 103);
            this.departmentDisciplinesButton.Name = "departmentDisciplinesButton";
            this.departmentDisciplinesButton.Size = new System.Drawing.Size(150, 23);
            this.departmentDisciplinesButton.TabIndex = 3;
            this.departmentDisciplinesButton.Text = "Дисциплины кафедры";
            this.departmentDisciplinesButton.UseVisualStyleBackColor = false;
            this.departmentDisciplinesButton.Click += new System.EventHandler(this.DepartmentDisciplinesButtonClick);
            // 
            // teachersOfDisciplineButton
            // 
            this.teachersOfDisciplineButton.BackColor = System.Drawing.Color.Aqua;
            this.teachersOfDisciplineButton.Location = new System.Drawing.Point(12, 298);
            this.teachersOfDisciplineButton.Name = "teachersOfDisciplineButton";
            this.teachersOfDisciplineButton.Size = new System.Drawing.Size(167, 23);
            this.teachersOfDisciplineButton.TabIndex = 4;
            this.teachersOfDisciplineButton.Text = "Преподаватели дисциплины";
            this.teachersOfDisciplineButton.UseVisualStyleBackColor = false;
            this.teachersOfDisciplineButton.Click += new System.EventHandler(this.TeachersOfDisciplineButtonClick);
            // 
            // teacherReferenceButton
            // 
            this.teacherReferenceButton.BackColor = System.Drawing.Color.Aqua;
            this.teacherReferenceButton.Location = new System.Drawing.Point(12, 227);
            this.teacherReferenceButton.Name = "teacherReferenceButton";
            this.teacherReferenceButton.Size = new System.Drawing.Size(156, 23);
            this.teacherReferenceButton.TabIndex = 5;
            this.teacherReferenceButton.Text = "Справка по преподавателю";
            this.teacherReferenceButton.UseVisualStyleBackColor = false;
            this.teacherReferenceButton.Click += new System.EventHandler(this.TeacherReferenceButtonClick);
            // 
            // teacherIdTextBox
            // 
            this.teacherIdTextBox.Location = new System.Drawing.Point(12, 256);
            this.teacherIdTextBox.Name = "teacherIdTextBox";
            this.teacherIdTextBox.Size = new System.Drawing.Size(156, 20);
            this.teacherIdTextBox.TabIndex = 6;
            // 
            // disciplineIdTextBox
            // 
            this.disciplineIdTextBox.Location = new System.Drawing.Point(12, 327);
            this.disciplineIdTextBox.Name = "disciplineIdTextBox";
            this.disciplineIdTextBox.Size = new System.Drawing.Size(156, 20);
            this.disciplineIdTextBox.TabIndex = 7;
            // 
            // updateTableButton
            // 
            this.updateTableButton.BackColor = System.Drawing.Color.Aqua;
            this.updateTableButton.Location = new System.Drawing.Point(18, 141);
            this.updateTableButton.Name = "updateTableButton";
            this.updateTableButton.Size = new System.Drawing.Size(150, 23);
            this.updateTableButton.TabIndex = 8;
            this.updateTableButton.Text = "Обновить таблицу";
            this.updateTableButton.UseVisualStyleBackColor = false;
            this.updateTableButton.Click += new System.EventHandler(this.UpdateTableButtonClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Lime;
            this.ClientSize = new System.Drawing.Size(799, 362);
            this.Controls.Add(this.updateTableButton);
            this.Controls.Add(this.disciplineIdTextBox);
            this.Controls.Add(this.teacherIdTextBox);
            this.Controls.Add(this.teacherReferenceButton);
            this.Controls.Add(this.teachersOfDisciplineButton);
            this.Controls.Add(this.departmentDisciplinesButton);
            this.Controls.Add(this.disciplinesButton);
            this.Controls.Add(this.teachersButton);
            this.Controls.Add(this.dataGridView);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.Button teachersButton;
        private System.Windows.Forms.Button disciplinesButton;
        private System.Windows.Forms.Button departmentDisciplinesButton;
        private System.Windows.Forms.Button teachersOfDisciplineButton;
        private System.Windows.Forms.Button teacherReferenceButton;
        private System.Windows.Forms.TextBox teacherIdTextBox;
        private System.Windows.Forms.TextBox disciplineIdTextBox;
        private System.Windows.Forms.Button updateTableButton;
    }
}

