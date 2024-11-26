using System;
using System.Data;
using System.Drawing;
using Npgsql;

namespace ASP_RGZ.Models
{
    public static class Database
    {
        private static readonly string host = "localhost";
        private static readonly string user = "postgres";
        private static readonly string dbName = "ASP_RGZ";
        private static readonly string port = "5432";
        private static readonly string password = "hugelong123";

        private static string conString = $"Server={host}; Username={user}; Database={dbName}; Port={port}; Password={password}; SSLMode=Prefer";
        private static NpgsqlConnection? connection;

        public static void Connect()
        {
            connection = new NpgsqlConnection(conString);
            connection.Open();
        }
        private static void Close()
        {
            connection?.Close();
        }

        public static List<Product> GetProducts()
        {
            Connect();
            string sql = 
                "SELECT *\n" +
                "FROM products;";
            using NpgsqlCommand command = new(sql, connection);
            List<Product> products = new();
            NpgsqlDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                int id = Convert.ToInt32(reader["id"]);
                int count = Convert.ToInt32(reader["count"]);
                string name = Convert.ToString(reader["name"]);
                int price = Convert.ToInt32(reader["price"]);
                string category = Convert.ToString(reader["category"]);
                Product product = new(id, count, name, price, category);
                products.Add(product);
            }
            Close();
            return products;
        }

        public static void UpdateProduct(Product product, int id)
        {
            Connect();
            string sql = 
                "UPDATE products\n" +
                "SET count = @count, name = @name, price = @price, category = @category\n" +
                "WHERE id = @id;";
            using NpgsqlCommand command = new(sql, connection);
            {
                command.Parameters.AddWithValue("count", product.Count);
                command.Parameters.AddWithValue("name", product.Name);
                command.Parameters.AddWithValue("price", product.Price);
                command.Parameters.AddWithValue("category", product.Catagory);
                command.Parameters.AddWithValue("id", id);
                command.ExecuteNonQuery();
            }
            Close();
        }
        public static void DeleteProduct(int id)
        {
            Connect();
            string sql = 
                "DELETE FROM products\n" +
                "WHERE id = @id;";
            using NpgsqlCommand command = new(sql, connection);
            {
                command.Parameters.AddWithValue("id", id);
                command.ExecuteNonQuery();
            }
            Close();
        }
        public static void AddProduct(Product product)
        {
            Connect();
            string sql = 
                "INSERT INTO products(count, name, price, category)\n" +
                "VALUES (@count, @name, @price, @category);";
            using NpgsqlCommand command = new(sql, connection);
            {
                command.Parameters.AddWithValue("count", product.Count);
                command.Parameters.AddWithValue("name", product.Name);
                command.Parameters.AddWithValue("price", product.Count);
                command.Parameters.AddWithValue("category", product.Catagory);
                command.ExecuteNonQuery();
            }
            Close();
        }
        public static Product GetProduct(int id)
        {
            Connect();
            Product product = new();
            string sql = 
                "SELECT * FROM products\n" +
                "WHERE id = @id;";
            using NpgsqlCommand command = new(sql, connection);
            {
                command.Parameters.AddWithValue("id", id);
                command.ExecuteNonQuery();
                NpgsqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    int count = Convert.ToInt32(reader["count"]);
                    string name = Convert.ToString(reader["name"]);
                    int price = Convert.ToInt32(reader["price"]);
                    string category = Convert.ToString(reader["category"]);
                    product = new(id, count, name, price, category);
                }
            }
            Close();
            return product;
        }
    }
}
