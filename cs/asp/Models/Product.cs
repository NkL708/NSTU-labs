using System.ComponentModel.DataAnnotations;

namespace ASP_RGZ.Models;
public class Product
{
    [Key]
    public int Id { get; set; }
    public int Count { get; set; }
    [Required]
    public string Name { get; set; }
    [Required]
    public int Price { get; set; }
    public string Catagory { get; set; }

    public Product(int Id, int Count, string Name,
        int Price, string Catagory)
    {
        this.Id = Id;
        this.Count = Count;
        this.Name = Name;
        this.Price = Price;
        this.Catagory = Catagory;
    }
    public Product() 
    {
        this.Name = "";
        this.Catagory = "";
    }
}
