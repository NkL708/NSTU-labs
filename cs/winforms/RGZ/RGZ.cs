using System;
using System.Data;
using System.Windows.Forms;
using Npgsql;

namespace RGZ
{
    public partial class RGZ : Form
    {
        private static readonly string host = "localhost";
        private static readonly string user = "postgres";
        private static readonly string dbName = "IN_RGZ";
        private static readonly string port = "5432";
        private static readonly string password = "hugelong123";
        private static string conString;
        private static NpgsqlConnection connection;
        private static string currentTable;

        public RGZ()
        {
            InitializeComponent();
            Connect();
        }

        private static void Connect()
        {
            conString = $"Server={host}; Username={user}; Database={dbName}; Port={port}; Password={password}; SSLMode=Prefer";
            connection = new NpgsqlConnection(conString);
            connection.Open();
        }
        private void TeachersButtonClick(object sender, EventArgs e)
        {
            using (NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(
                "SELECT id, last_name, first_name, patronymic,\n" +
                "department_name, employment_date\n" +
                "FROM teachers;", connection))
            {
                DataTable dataTable = new DataTable();
                adapter.Fill(dataTable);
                dataGridView.DataSource = dataTable;
            }
            currentTable = "teachers";
        }

        private void DisciplinesButtonClick(object sender, EventArgs e)
        {
            using (NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(
                "SELECT id, name, speciality, semester\n" +
                "FROM disciplines", connection))
            {
                DataTable dataTable = new DataTable();
                adapter.Fill(dataTable);
                dataGridView.DataSource = dataTable;
            }
            currentTable = "disciplines";
        }

        private void DepartmentDisciplinesButtonClick(object sender, EventArgs e)
        {
            using (NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(
                "SELECT id, teacher_id, discipline_id, hours_count\n" +
                "FROM department_disciplines", connection))
            {
                DataTable dataTable = new DataTable();
                adapter.Fill(dataTable);
                dataGridView.DataSource = dataTable;
            }
            currentTable = "department_disciplines";
        }

        private void UpdateTableButtonClick(object sender, EventArgs e)
        {
            
            ClearDBTable(currentTable);
            if (currentTable == null)
                return;
            if (dataGridView.Rows.Count == 0)
                return;
            DataTable table = (DataTable)dataGridView.DataSource;
            if (currentTable == "teachers")
            {
                foreach (DataRow row in table.Rows)
                {
                    if (row.RowState == DataRowState.Deleted)
                        continue;
                    using (NpgsqlCommand command = new NpgsqlCommand(
                        "INSERT INTO teachers(id, last_name, first_name, \n" +
                        "patronymic, department_name, employment_date)\n" +
                        "VALUES (@id, @ln, @fn, @p, @dn, @ed);", connection))
                    {
                        command.Parameters.AddWithValue("id", row[0]);
                        command.Parameters.AddWithValue("ln", row[1]);
                        command.Parameters.AddWithValue("fn", row[2]);
                        command.Parameters.AddWithValue("p", row[3]);
                        command.Parameters.AddWithValue("dn", row[4]);
                        command.Parameters.AddWithValue("ed", row[5]);
                        command.ExecuteNonQuery();
                    }
                }
            }
            if (currentTable == "disciplines")
            {
                foreach (DataRow row in table.Rows)
                {
                    if (row.RowState == DataRowState.Deleted)
                        continue;
                    using (NpgsqlCommand command = new NpgsqlCommand(
                        "INSERT INTO disciplines(id, name, speciality, semester)\n" +
                        "VALUES (@id, @n, @sp, @se);", connection))
                    {
                        command.Parameters.AddWithValue("id", row[0]);
                        command.Parameters.AddWithValue("n", row[1]);
                        command.Parameters.AddWithValue("sp", row[2]);
                        command.Parameters.AddWithValue("se", row[3]);
                        command.ExecuteNonQuery();
                    }
                }
            }
            if (currentTable == "department_disciplines")
            {
                foreach (DataRow row in table.Rows)
                {
                    if (row.RowState == DataRowState.Deleted)
                        continue;
                    using (NpgsqlCommand command = new NpgsqlCommand(
                        "INSERT INTO department_disciplines(id, \n" +
                        "teacher_id, discipline_id, hours_count)\n" +
                        "VALUES (@id, @tid, @hc, @did);", connection))
                    {
                        command.Parameters.AddWithValue("id", row[0]);
                        command.Parameters.AddWithValue("tid", row[1]);
                        command.Parameters.AddWithValue("hc", row[2]);
                        command.Parameters.AddWithValue("did", row[3]);
                        command.ExecuteNonQuery();
                    }
                }
            }
        }

        private static void ClearDBTable(string tableName)
        {
            using (NpgsqlCommand command = new NpgsqlCommand(
                $"DELETE FROM {tableName};", connection))
            {
                command.ExecuteNonQuery();
            }
        }

        private void TeacherReferenceButtonClick(object sender, EventArgs e)
        {
            using (NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(
                "SELECT disciplines.name, disciplines.speciality, \n" +
                "disciplines.semester, dep_dis.hours_count\n" +
                "FROM teachers\n" +
                "JOIN department_disciplines AS dep_dis ON dep_dis.teacher_id = teachers.id\n" +
                "JOIN disciplines ON disciplines.id = dep_dis.discipline_id\n" +
                $"WHERE teacher_id = {teacherIdTextBox.Text};", connection))
            {
                DataTable table = new DataTable();
                adapter.Fill(table);
                dataGridView.DataSource = table;
            }
            currentTable = null;
        }

        private void TeachersOfDisciplineButtonClick(object sender, EventArgs e)
        {

            using (NpgsqlDataAdapter adapter = new NpgsqlDataAdapter(
                "SELECT teachers.id, teachers.last_name, teachers.first_name, \n" +
                "teachers.patronymic, teachers.department_name, teachers.employment_date\n" +
                "FROM department_disciplines AS dep_dis\n" +
                "JOIN teachers ON dep_dis.teacher_id = teachers.id\n" +
                $"WHERE discipline_id = {disciplineIdTextBox.Text}; ", connection))
            {
                DataTable table = new DataTable();
                adapter.Fill(table);
                dataGridView.DataSource = table;
            }
            currentTable = null;
        }
    }
}