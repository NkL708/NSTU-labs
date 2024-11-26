namespace Information_networks
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.initButton = new System.Windows.Forms.Button();
            this.openSessionButton = new System.Windows.Forms.Button();
            this.closeSessionButton = new System.Windows.Forms.Button();
            this.connectionLabel = new System.Windows.Forms.Label();
            this.incorrectFields = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.tableView = new System.Windows.Forms.RichTextBox();
            this.showUsersButton = new System.Windows.Forms.Button();
            this.gridView = new System.Windows.Forms.DataGridView();
            this.insertButton = new System.Windows.Forms.Button();
            this.deleteButton = new System.Windows.Forms.Button();
            this.showFunctionsButton = new System.Windows.Forms.Button();
            this.executeSqlButton = new System.Windows.Forms.Button();
            this.sqlText = new System.Windows.Forms.RichTextBox();
            this.updateDBButton = new System.Windows.Forms.Button();
            this.treeView = new System.Windows.Forms.TreeView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.dumpItem = new System.Windows.Forms.ToolStripMenuItem();
            this.restoreItem = new System.Windows.Forms.ToolStripMenuItem();
            this.passwordTextBox = new CueTextBox();
            this.serverPortTextBox = new CueTextBox();
            this.serverAdressTextBox = new CueTextBox();
            this.loginTextBox = new CueTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridView)).BeginInit();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // initButton
            // 
            this.initButton.BackColor = System.Drawing.Color.Lime;
            this.initButton.Location = new System.Drawing.Point(23, 34);
            this.initButton.Name = "initButton";
            this.initButton.Size = new System.Drawing.Size(130, 25);
            this.initButton.TabIndex = 0;
            this.initButton.Text = "Инициализация";
            this.initButton.UseVisualStyleBackColor = false;
            this.initButton.Click += new System.EventHandler(this.InitButtonClick);
            // 
            // openSessionButton
            // 
            this.openSessionButton.BackColor = System.Drawing.Color.Lime;
            this.openSessionButton.Enabled = false;
            this.openSessionButton.Location = new System.Drawing.Point(23, 80);
            this.openSessionButton.Name = "openSessionButton";
            this.openSessionButton.Size = new System.Drawing.Size(130, 25);
            this.openSessionButton.TabIndex = 1;
            this.openSessionButton.Text = "Открытие сеанса";
            this.openSessionButton.UseVisualStyleBackColor = false;
            this.openSessionButton.Click += new System.EventHandler(this.OpenSessionButtonClick);
            // 
            // closeSessionButton
            // 
            this.closeSessionButton.BackColor = System.Drawing.Color.Lime;
            this.closeSessionButton.Enabled = false;
            this.closeSessionButton.Location = new System.Drawing.Point(23, 130);
            this.closeSessionButton.Name = "closeSessionButton";
            this.closeSessionButton.Size = new System.Drawing.Size(130, 25);
            this.closeSessionButton.TabIndex = 2;
            this.closeSessionButton.Text = "Закрытие сеанса";
            this.closeSessionButton.UseVisualStyleBackColor = false;
            this.closeSessionButton.Click += new System.EventHandler(this.CloseSessionButtonClick);
            // 
            // connectionLabel
            // 
            this.connectionLabel.AutoSize = true;
            this.connectionLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F);
            this.connectionLabel.ForeColor = System.Drawing.Color.Red;
            this.connectionLabel.Location = new System.Drawing.Point(170, 116);
            this.connectionLabel.Name = "connectionLabel";
            this.connectionLabel.Size = new System.Drawing.Size(111, 17);
            this.connectionLabel.TabIndex = 12;
            this.connectionLabel.Text = "Не подключено";
            // 
            // incorrectFields
            // 
            this.incorrectFields.AutoSize = true;
            this.incorrectFields.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.25F);
            this.incorrectFields.ForeColor = System.Drawing.Color.Red;
            this.incorrectFields.Location = new System.Drawing.Point(170, 139);
            this.incorrectFields.Name = "incorrectFields";
            this.incorrectFields.Size = new System.Drawing.Size(61, 17);
            this.incorrectFields.TabIndex = 13;
            this.incorrectFields.Text = "Ошибка";
            this.incorrectFields.Visible = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Information_networks.Properties.Resources.cow;
            this.pictureBox1.Location = new System.Drawing.Point(173, 172);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(125, 62);
            this.pictureBox1.TabIndex = 14;
            this.pictureBox1.TabStop = false;
            // 
            // tableView
            // 
            this.tableView.Location = new System.Drawing.Point(23, 265);
            this.tableView.Name = "tableView";
            this.tableView.Size = new System.Drawing.Size(270, 151);
            this.tableView.TabIndex = 15;
            this.tableView.Text = "";
            // 
            // showUsersButton
            // 
            this.showUsersButton.BackColor = System.Drawing.Color.Lime;
            this.showUsersButton.Enabled = false;
            this.showUsersButton.Location = new System.Drawing.Point(23, 236);
            this.showUsersButton.Name = "showUsersButton";
            this.showUsersButton.Size = new System.Drawing.Size(87, 23);
            this.showUsersButton.TabIndex = 16;
            this.showUsersButton.Text = "Просмотр";
            this.showUsersButton.UseVisualStyleBackColor = false;
            this.showUsersButton.Click += new System.EventHandler(this.ViewButtonClick);
            // 
            // gridView
            // 
            this.gridView.BackgroundColor = System.Drawing.SystemColors.Window;
            this.gridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridView.Location = new System.Drawing.Point(316, 265);
            this.gridView.Name = "gridView";
            this.gridView.Size = new System.Drawing.Size(291, 150);
            this.gridView.TabIndex = 18;
            // 
            // insertButton
            // 
            this.insertButton.BackColor = System.Drawing.Color.Lime;
            this.insertButton.Enabled = false;
            this.insertButton.Location = new System.Drawing.Point(343, 133);
            this.insertButton.Name = "insertButton";
            this.insertButton.Size = new System.Drawing.Size(107, 23);
            this.insertButton.TabIndex = 19;
            this.insertButton.Text = "Вставить";
            this.insertButton.UseVisualStyleBackColor = false;
            this.insertButton.Click += new System.EventHandler(this.InsertButtonClick);
            // 
            // deleteButton
            // 
            this.deleteButton.BackColor = System.Drawing.Color.Lime;
            this.deleteButton.Enabled = false;
            this.deleteButton.Location = new System.Drawing.Point(343, 172);
            this.deleteButton.Name = "deleteButton";
            this.deleteButton.Size = new System.Drawing.Size(107, 23);
            this.deleteButton.TabIndex = 20;
            this.deleteButton.Text = "Удалить";
            this.deleteButton.UseVisualStyleBackColor = false;
            this.deleteButton.Click += new System.EventHandler(this.DeleteButtonClick);
            // 
            // showFunctionsButton
            // 
            this.showFunctionsButton.BackColor = System.Drawing.Color.Lime;
            this.showFunctionsButton.Enabled = false;
            this.showFunctionsButton.Location = new System.Drawing.Point(316, 236);
            this.showFunctionsButton.Name = "showFunctionsButton";
            this.showFunctionsButton.Size = new System.Drawing.Size(118, 23);
            this.showFunctionsButton.TabIndex = 21;
            this.showFunctionsButton.Text = "Просмотр функций";
            this.showFunctionsButton.UseVisualStyleBackColor = false;
            this.showFunctionsButton.Click += new System.EventHandler(this.ShowFunctionsButtonClick);
            // 
            // executeSqlButton
            // 
            this.executeSqlButton.BackColor = System.Drawing.Color.Lime;
            this.executeSqlButton.Enabled = false;
            this.executeSqlButton.Location = new System.Drawing.Point(507, 87);
            this.executeSqlButton.Name = "executeSqlButton";
            this.executeSqlButton.Size = new System.Drawing.Size(107, 23);
            this.executeSqlButton.TabIndex = 22;
            this.executeSqlButton.Text = "Выполнить";
            this.executeSqlButton.UseVisualStyleBackColor = false;
            this.executeSqlButton.Click += new System.EventHandler(this.ExecuteSqlButtonClick);
            // 
            // sqlText
            // 
            this.sqlText.Location = new System.Drawing.Point(456, 116);
            this.sqlText.Name = "sqlText";
            this.sqlText.Size = new System.Drawing.Size(158, 114);
            this.sqlText.TabIndex = 23;
            this.sqlText.Text = "";
            // 
            // updateDBButton
            // 
            this.updateDBButton.BackColor = System.Drawing.Color.Lime;
            this.updateDBButton.Enabled = false;
            this.updateDBButton.Location = new System.Drawing.Point(453, 236);
            this.updateDBButton.Name = "updateDBButton";
            this.updateDBButton.Size = new System.Drawing.Size(103, 23);
            this.updateDBButton.TabIndex = 24;
            this.updateDBButton.Text = "Обновить БД";
            this.updateDBButton.UseVisualStyleBackColor = false;
            this.updateDBButton.Click += new System.EventHandler(this.UpdateDBButtonClick);
            // 
            // treeView
            // 
            this.treeView.Location = new System.Drawing.Point(628, 69);
            this.treeView.Name = "treeView";
            this.treeView.Size = new System.Drawing.Size(121, 346);
            this.treeView.TabIndex = 25;
            this.treeView.NodeMouseDoubleClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.TreeViewNodeMouseDoubleClick);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dumpItem,
            this.restoreItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(764, 24);
            this.menuStrip.TabIndex = 27;
            this.menuStrip.Text = "menuStrip1";
            // 
            // dumpItem
            // 
            this.dumpItem.Name = "dumpItem";
            this.dumpItem.Size = new System.Drawing.Size(78, 20);
            this.dumpItem.Text = "Сохранить";
            this.dumpItem.Click += new System.EventHandler(this.DumpItemClick);
            // 
            // restoreItem
            // 
            this.restoreItem.Name = "restoreItem";
            this.restoreItem.Size = new System.Drawing.Size(94, 20);
            this.restoreItem.Text = "Восстановить";
            this.restoreItem.Click += new System.EventHandler(this.RestoreItemClick);
            // 
            // passwordTextBox
            // 
            this.passwordTextBox.Cue = "Пароль";
            this.passwordTextBox.Enabled = false;
            this.passwordTextBox.Location = new System.Drawing.Point(343, 85);
            this.passwordTextBox.Name = "passwordTextBox";
            this.passwordTextBox.PasswordChar = '*';
            this.passwordTextBox.Size = new System.Drawing.Size(130, 20);
            this.passwordTextBox.TabIndex = 5;
            // 
            // serverPortTextBox
            // 
            this.serverPortTextBox.Cue = "Порт";
            this.serverPortTextBox.Enabled = false;
            this.serverPortTextBox.Location = new System.Drawing.Point(173, 83);
            this.serverPortTextBox.Name = "serverPortTextBox";
            this.serverPortTextBox.Size = new System.Drawing.Size(130, 20);
            this.serverPortTextBox.TabIndex = 7;
            this.serverPortTextBox.Text = "5432";
            // 
            // serverAdressTextBox
            // 
            this.serverAdressTextBox.Cue = "Адрес сервера";
            this.serverAdressTextBox.Enabled = false;
            this.serverAdressTextBox.Location = new System.Drawing.Point(173, 37);
            this.serverAdressTextBox.Name = "serverAdressTextBox";
            this.serverAdressTextBox.Size = new System.Drawing.Size(130, 20);
            this.serverAdressTextBox.TabIndex = 6;
            this.serverAdressTextBox.Text = "localhost";
            // 
            // loginTextBox
            // 
            this.loginTextBox.Cue = "Логин";
            this.loginTextBox.Enabled = false;
            this.loginTextBox.Location = new System.Drawing.Point(343, 39);
            this.loginTextBox.Name = "loginTextBox";
            this.loginTextBox.Size = new System.Drawing.Size(130, 20);
            this.loginTextBox.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Aqua;
            this.ClientSize = new System.Drawing.Size(764, 429);
            this.Controls.Add(this.menuStrip);
            this.Controls.Add(this.treeView);
            this.Controls.Add(this.updateDBButton);
            this.Controls.Add(this.sqlText);
            this.Controls.Add(this.executeSqlButton);
            this.Controls.Add(this.showFunctionsButton);
            this.Controls.Add(this.deleteButton);
            this.Controls.Add(this.insertButton);
            this.Controls.Add(this.gridView);
            this.Controls.Add(this.showUsersButton);
            this.Controls.Add(this.tableView);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.incorrectFields);
            this.Controls.Add(this.passwordTextBox);
            this.Controls.Add(this.connectionLabel);
            this.Controls.Add(this.serverPortTextBox);
            this.Controls.Add(this.serverAdressTextBox);
            this.Controls.Add(this.loginTextBox);
            this.Controls.Add(this.closeSessionButton);
            this.Controls.Add(this.openSessionButton);
            this.Controls.Add(this.initButton);
            this.KeyPreview = true;
            this.MainMenuStrip = this.menuStrip;
            this.Name = "Form1";
            this.Text = "Джавы-джуны";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridView)).EndInit();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button initButton;
        private System.Windows.Forms.Button openSessionButton;
        private System.Windows.Forms.Button closeSessionButton;
        private CueTextBox loginTextBox;
        private CueTextBox serverAdressTextBox;
        private CueTextBox serverPortTextBox;
        private System.Windows.Forms.Label connectionLabel;
        private CueTextBox passwordTextBox;
        private System.Windows.Forms.Label incorrectFields;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.RichTextBox tableView;
        private System.Windows.Forms.Button showUsersButton;
        private System.Windows.Forms.DataGridView gridView;
        private System.Windows.Forms.Button insertButton;
        private System.Windows.Forms.Button deleteButton;
        private System.Windows.Forms.Button showFunctionsButton;
        private System.Windows.Forms.Button executeSqlButton;
        private System.Windows.Forms.RichTextBox sqlText;
        private System.Windows.Forms.Button updateDBButton;
        private System.Windows.Forms.TreeView treeView;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem dumpItem;
        private System.Windows.Forms.ToolStripMenuItem restoreItem;
    }
}

