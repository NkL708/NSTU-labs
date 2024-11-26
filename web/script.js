function ajax(index)
{
    var cars = document.getElementById(`cars${index}`)
    index++
    var newCars = cars.cloneNode(true)
    value = cars.value
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", `server.php?ajax=${value}`, true)
    xhttp.send();

    xhttp.onreadystatechange = function () 
    {
        // If xhttp success
        if (this.readyState == 4 && this.status == 200) 
        {
            console.log(this.responseText);
            if (this.responseText) 
            {
                for (var i = 0; i < cars.length; i++)
                {
                    if (cars.options[i].value == cars.value) 
                    {
                        newCars.remove(i);
                    }
                }
                
            }
            
            newCars.id = "cars" + index
            newCars.setAttribute("onchange", `ajax(${index})`);
            document.body.append(newCars)
            cars.removeAttribute("onchange");
        }
    }
}