function searchemployee() {

    var searchInput = document.getElementById('searchBar').value;
    
    $.post({
        url:'../database/searchemployee',
        data: {'employeeName': searchInput},
        datatype: 'json',

        success: function(data)
        {

            obj = JSON.parse(data)
            var inner = new Object()
            var inner_html =""
            for (var i=0; i<obj.length; i++) 
            {
                inner = obj[i]
                delete inner.model

                var section = "<section id ='";
                section += inner.pk;
                section += "' class= 'employeename'> <div>Name:&emsp; <input id='name' class='field' type='text' value='";
                section += inner.fields.empName;
                section += "' readonly size='10'></div> <div>ID:&emsp; <input id='ID' class='field' type='number' value='";
                section += inner.pk;
                section += "' readonly size='10'> </div> <div>birth date:&emsp; <input id='bdate' class='field' type='date' value='";
                section += inner.fields.bdate;
                section += "' readonly size='4'></div> <div>email:&emsp; <input id='email' class='field' type='text' value='";
                section += inner.fields.email;
                section += "' readonly size='4'></div> <div> address:&emsp; <input id='address' class='field' type='text' value='";
                section += inner.fields.address;
                section += "' readonly size='4'></div> <div> phone number:&emsp; <input id='phone' class='field' type='text' value='";
                section += inner.fields.phone;
                section += "' readonly size='4'></div> <div> salary:&emsp; <input id='salary' class='field' type='number' value='";
                section += inner.fields.salary;
                section += "' readonly size='4'></div> <div> available vacation days :&emsp; <input id='availablevacation' class='field' type='text' value='";
                section += inner.fields.availablevacation;
                section += "' readonly size='4'></div> <div> approved vacation days :&emsp; <input id='approvedvacation' class='field' type='text' value='";
                section += inner.fields.approvedvacation;
                section += "' readonly size='4'></div> ";

                section += " <input id = '";
                section += inner.pk;
                section += "' onclick=\"preview('";
                section += inner.pk;
                section += "')\" class='button preview' title ='review' src = '../static/style/preview.png' type='image'/> <input id = '";
                section += inner.pk;
                section += "' onclick=\"deletemp('";
                section += inner.pk;
                section += "')\" class='button delete' title = 'delete' src = \"../static/style/delete1.png\" type='image'/></section>";
                inner_html += section;
                
            }
            document.getElementById('employees').innerHTML = inner_html;

            if(obj.length == 0)
                window.alert("no employee found")
            else
                window.alert("employee found")
        }

    });
}
function deletemp(id){
    var choice = confirm("are you sure you want to delete this employee?");
    if(choice)  
    {
        $.post({
            url:'../database/deleteemployee',
            data: {'pk': id},
            datatype: 'json',
    
            success: function(data)
            {
                render()
                window.alert("emp deleted successfully!");
            }
        }
        );
    }

}
