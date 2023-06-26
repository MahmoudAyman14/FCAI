using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SuperMarketDBCODING
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'superMarketDBDataSet.PRODUCT' table. You can move, or remove it, as needed.
            
            
        }

        private void label1_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = " INSERT INTO PRODUCT VALUES('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "','" + textBox7.Text + "','" + textBox8.Text + "','" + textBox9.Text + "')";
            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Insertion was successfully completed");
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.pRODUCTTableAdapter.Fill(this.superMarketDBDataSet.PRODUCT);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = "UPDATE PRODUCT SET PName = '" + textBox2.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET PType = '" + textBox3.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET Pprice = '" + textBox4.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET PQuantity = '" + textBox5.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET PDiscount = '" + textBox6.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET Pmonth = '" + textBox7.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET NumCustomers = '" + textBox8.Text + "' WHERE PId = '" + textBox1.Text + "'";
            sqlCommand.CommandText = "UPDATE PRODUCT SET quantity_bought = '" + textBox9.Text + "' WHERE PId = '" + textBox1.Text + "'";

            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Updating was successfully completed");
        }

        private void button3_Click(object sender, EventArgs e)
        {

            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = "DELETE FROM PRODUCT WHERE PId = '" + textBox1.Text + "'";
            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Deletion was successfully completed");
        }
    }
}
