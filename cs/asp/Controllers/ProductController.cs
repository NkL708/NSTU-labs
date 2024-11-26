using ASP_RGZ.Models;
using Microsoft.AspNetCore.Mvc;

namespace ASP_RGZ.Controllers
{
    public class ProductController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }
        [HttpGet]
        public IActionResult Create()
        {
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult Create(Product product) 
        {
            if (ModelState.IsValid)
            {
                Database.AddProduct(product);
                return RedirectToAction("Index");
            }
            return View(product);
        }
        [HttpGet]
        public IActionResult Update(int id) 
        {
            var product = Database.GetProduct(id);
            return View(product); 
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult Update(Product product, int id) 
        {
            if (ModelState.IsValid)
            {
                Database.UpdateProduct(product, id);
                return RedirectToAction("Index");
            }
            return View(product);
        }
        [HttpGet]
        public IActionResult Delete(int id) 
        { 
            var product = Database.GetProduct(id);
            return View(product); 
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        [ActionName("Delete")]
        public IActionResult DeletePost(int id)
        {
            Database.DeleteProduct(id);
            return RedirectToAction("Index");
        }
    }
}
