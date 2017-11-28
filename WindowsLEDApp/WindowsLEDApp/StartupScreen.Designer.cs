namespace WindowsLEDApp
{
    partial class StartupScreen
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ComportSelector = new System.Windows.Forms.ComboBox();
            this.ComPortButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ComportSelector
            // 
            this.ComportSelector.FormattingEnabled = true;
            this.ComportSelector.Location = new System.Drawing.Point(13, 13);
            this.ComportSelector.Name = "ComportSelector";
            this.ComportSelector.Size = new System.Drawing.Size(366, 32);
            this.ComportSelector.TabIndex = 0;
            // 
            // ComPortButton
            // 
            this.ComPortButton.Location = new System.Drawing.Point(403, 13);
            this.ComPortButton.Name = "ComPortButton";
            this.ComPortButton.Size = new System.Drawing.Size(163, 36);
            this.ComPortButton.TabIndex = 1;
            this.ComPortButton.Text = "Select";
            this.ComPortButton.UseVisualStyleBackColor = true;
            // 
            // StartupScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(713, 236);
            this.Controls.Add(this.ComPortButton);
            this.Controls.Add(this.ComportSelector);
            this.Name = "StartupScreen";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox ComportSelector;
        private System.Windows.Forms.Button ComPortButton;
    }
}

