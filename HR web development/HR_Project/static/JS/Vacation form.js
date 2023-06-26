function submitvacation(){
    console.log("low")
    var name = document.getElementById('name').value;
    var ID = document.getElementById('ID').value;
    var vacreason = document.getElementById('vacationreason').value;
    var vacfdate = document.getElementById('fdate').value;
    var vactdate = document.getElementById('tdate').value;
    console.log("hii")
    $.post({
        url: '../database/submitvac',
        data: {'ID': ID, 'name': name, 'vacreason':vacreason,'vacfdate':vacfdate,'vactdate':vactdate},
        datatype: 'json',
        success: function(data){
            console.log(data)
            if(data.exist == false){
                
                alert("vacation submitted successfully")
            }
            else{
                alert("vacation already exists")
            }
        }
    })
}
