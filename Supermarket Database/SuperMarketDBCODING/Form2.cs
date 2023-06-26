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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'superMarketDBDataSet.PRODUCT' table. You can move, or remove it, as needed.
            this.pRODUCTTableAdapter.Fill(this.superMarketDBDataSet.PRODUCT);
            // TODO: This line of code loads data into the 'superMarketDBDataSet.PERSON' table. You can move, or remove it, as needed.
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            this.pERSONTableAdapter.Fill(this.superMarketDBDataSet.PERSON);

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            this.pERSONTableAdapter.Fill(this.superMarketDBDataSet.PERSON);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = "DELETE FROM PERSON WHERE PId = '" + textBox1.Text + "'";
            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Deletion was successfully completed");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = "UPDATE PERSON SET FirstName = '" + textBox1.Text + "' WHERE ID = '" + textBox3.Text + "'";
            sqlCommand.CommandText = "UPDATE PERSON SET LastName = '" + textBox2.Text + "' WHERE ID = '" + textBox3.Text + "'";
            sqlCommand.CommandText = "UPDATE PERSON SET Cflag = '" + textBox4.Text + "' WHERE ID = '" + textBox3.Text + "'";
            sqlCommand.CommandText = "UPDATE PERSON SET Caddress = '" + textBox5.Text + "' WHERE ID = '" + textBox3.Text + "'";
            sqlCommand.CommandText = "UPDATE PERSON SET Cphone = '" + textBox6.Text + "' WHERE ID = '" + textBox3.Text + "'";
            
            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Updating was successfully completed");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlConnection sqlConnection = new SqlConnection("Data Source=MOELSHERIF;Initial Catalog=SuperMarketDB;Integrated Security=True");
            SqlCommand sqlCommand = new SqlCommand();
            sqlCommand.Connection = sqlConnection;
            sqlCommand.CommandText = " INSERT INTO PERSON VALUES('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "')";
            //sqlCommand.ExecuteNonQuery();
            sqlConnection.Close();
            MessageBox.Show("Insertion was successfully completed");
        }
    }
}
