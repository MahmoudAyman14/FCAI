from django.shortcuts import render
from ast import Pass
from enum import unique
from urllib import request
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
from .models import *
from django.core import serializers
# Create your views here.
def getVacations(request):
    ls = serializers.serialize("json", vacation.objects.all())
    return JsonResponse(ls, safe=False)

def getaccVacations(request):
    ls = serializers.serialize("json", accvacation.objects.all())
    return JsonResponse(ls, safe=False)

def searchemployee(request):

    searchInput = request.POST['employeeName']
    searchResults = Employees.objects.filter(empName = searchInput)

    searchResults = serializers.serialize("json", searchResults)

    return JsonResponse(searchResults, safe=False)
    
def addemployee(request):
    id = request.POST['ID']
    name = request.POST['name']
    email= request.POST['email']
    address = request.POST['add']
    phone = request.POST['phone']
    availablevacation = request.POST['avd']
    approvedvacation=request.POST['apd']
    salary = request.POST['sal']
    date=request.POST['date']
    exist = Employees.objects.filter(empID = id).exists()
    data = {"exist": exist}
    
    if exist == False:
        newemployee = Employees(empID = id, empName = name,
                        bdate = date, email = email,
                        phone = phone, address = address,
                        availablevacation = availablevacation, approvedvacation = approvedvacation ,salary=salary,gender=0,Mstate=0)
        newemployee.save()
    return JsonResponse(data)
    
def submitvac(request):
    ID= request.POST['ID']
    name = request.POST['name']
    vacreason=request.POST['vacreason']
    vacfdate=request.POST['vacfdate']
    vactdate=request.POST['vactdate']
    exist = vacation.objects.filter(empID = ID).exists()
    data = {"exist": exist}
    
    if exist == False:
        newvacation = vacation(empID=ID, empName = name,
                        vacfdate = vacfdate, vactdate = vactdate,vacreason = vacreason)
        newvacation.save()
    return JsonResponse(data)
    
def acceptvac(request):
    ID= request.POST['ID']
    name = request.POST['name']
    vacreason=request.POST['vacreason']
    vacfdate=request.POST['vacfdate']
    vactdate=request.POST['vactdate']
    exist = accvacation.objects.filter(empID = ID).exists()
    data = {"exist": exist}
    
    if exist == False:
        newvacation = accvacation(empID=ID, empName = name,
                        vacfdate = vacfdate, vactdate = vactdate,vacreason = vacreason)
        newvacation.save()
    return JsonResponse(data)


def deletevac(request):

    PK = request.POST['pk']

    deletedLab = vacation.objects.get(pk = PK)

    deletedLab.delete()

    return HttpResponse()

def deleteemployee(request):

    PK = request.POST['pk']

    deletedLab = Employees.objects.get(pk = PK)

    deletedLab.delete()

    return HttpResponse()