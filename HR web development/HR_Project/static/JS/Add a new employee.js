function addemployee(){
    console.log("high")
    var name = document.getElementById('username').value;
    var ID = document.getElementById('ID').value;
    var email = document.getElementById('email').value;
    var address = document.getElementById('add').value;
    var phone = document.getElementById('Pnumber').value;
    var salary = document.getElementById('S').value;
    var date= document.getElementById('DOB').value;
    var availablevacation = document.getElementById('available days').value;
    var approvedvacation = document.getElementById('approved days').value;
   
    console.log("hello")
    $.post({

        url: '../database/addemployee',
        data: {'ID': ID, 'name': name, 'email' : email, 'add':address,
        'phone':phone, 'sal':salary,
        'avd':availablevacation, 'apd':approvedvacation,'date':date},
        datatype: 'json',
        success: function(data){
            console.log(data)
            if(data.exist == false){
                
                alert("Employee added successfully")
            }
            else{
                alert("Employee already exists")
            }
        }
    })
}
