using Microsoft.AspNetCore.Mvc;

namespace ASP_RGZ.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }


    }
}
