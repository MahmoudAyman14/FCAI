function render(){
    $.ajax({
        url:'../database/getVacations',
        method: 'GET',
        success: function(data)
        {
            console.log(data)
            obj = JSON.parse(data)
            var inner = new Object()
            console.log(obj)
            var inner_html =""
            for (var i=0; i<obj.length; i++) 
            {
                inner = obj[i]
                delete inner.model
                console.log(inner)
                var section = "<section id ='";
                section += inner.pk;
                section += "' class= 'employeeName'> <div>Employee Name:&emsp; <input id='name' class='field' type='text' value='";
                section += inner.fields.empName;
                section += "' readonly size='10'></div> <div>ID:&emsp; <input id='ID' class='field' type='number' value='";
                section += inner.pk;
                section += "' readonly size='4'> </div> <div>vacation start:&emsp; <input id='tdate' class='field' type='date' value='";
                section += inner.fields.vacfdate;
                section += "' readonly size='4'> </div> <div>vacation end:&emsp; <input id='fdate' class='field' type='date' value='";
                section += inner.fields.vactdate;
                section += "' readonly size='4'></div> <div>vacation reason:&emsp; <input id='vacationreason' class='field' type='text' value='";
                section += inner.fields.vacreason;
                section += "' readonly size='4'></div> ";
              
                section += " <input id = '";
                section += inner.pk;
                section += "' onclick=\"acceptvacation('";
                section += inner.pk;
                section += "')\" class='button accept' title ='accept' src = \"../static/style/accept1.png\" type='image'/> <input id = '";
                section += inner.pk;
                section += "' onclick=\"deletevac('";
                section += inner.pk;
                section += "')\" class='button reject' title = 'reject' src = \"../static/style/reject.png\" type='image'/></section>";
                
                
                inner_html += section;
                
            }
            document.getElementById('vacation').innerHTML = inner_html;
        }
    }) 
}
function deletevac(id){
    var choice = confirm("are you sure you want to reject the vacation ?");
    if(choice)  
    {
        $.post({
            url:'../database/deletevac',
            data: {'pk': id},
            datatype: 'json',
    
            success: function(data)
            {
                render()
                window.alert("lab deleted successfully!");
            }
        }
        );
    }

}

function acceptvacation(){
    console.log("low")
    var name = document.getElementById('name').value;
    var ID = document.getElementById('ID').value;
    var vacreason = document.getElementById('vacationreason').value;
    var vacfdate = document.getElementById('fdate').value;
    var vactdate = document.getElementById('tdate').value;
    console.log("hii")
    $.post({
        url: '../database/acceptvac',
        data: {'ID': ID, 'name': name, 'vacreason':vacreason,'vacfdate':vacfdate,'vactdate':vactdate},
        datatype: 'json',
        success: function(data){
            console.log(data)
            if(data.exist == false){
                
                alert("vacation acceptted successfully")
            }
            else{
                alert("vacation already exists")
            }
        }
    })
}

