from django.http import HttpResponse 
from django.shortcuts import render

def search(request):
    return render(request,'Search.html')

def home(request):
    return render(request,'Home.html') 

def submittedvacations(request):
    return render(request,'Submitted vacations.html')

def updateanexistingemployee(request):
    return render(request,'Update an existing employee.html')

def vacationform(request):
    return render(request,'Vacation form.html')

def vacations(request):
    return render(request,'Vacations.html')

def addanewemployee(request):
    return render(request,'Add a new employee.html')

def editemployeedata(request):
    return render(request,'Edit employee data.html') 

def homepage(request):
    return render(request,'Home Page.html')