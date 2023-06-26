from tkinter import CASCADE
from django.db import models

class vacation(models.Model):
    empID = models.IntegerField(unique = True, primary_key=True, default= 0)
    empName = models.CharField(max_length=30)
    vacfdate = models.DateField(null = True)
    vactdate = models.DateField(null = True)
    vacreason = models.CharField(max_length=500)

    def str(self):
        return self.empName
 
class accvacation(models.Model):
    empID = models.IntegerField(unique = True, primary_key=True, default= 0)
    empName = models.CharField(max_length=30)
    vacfdate = models.DateField(null = True)
    vactdate = models.DateField(null = True)
    vacreason = models.CharField(max_length=500)

    def str(self):
        return self.empName
    
class Employees(models.Model):
    empID = models.IntegerField(unique = True, primary_key=True, default= 0)
    empName = models.CharField(max_length=30)
    bdate = models.DateField(null = True)
    email= models.CharField(max_length=50)
    phone = models.CharField(max_length=11)
    address = models.CharField(max_length=300)
    salary= models.IntegerField(null = True)
    availablevacation=models.IntegerField(null = True)
    approvedvacation=models.IntegerField(null = True)
    GENDER_MALE = 0
    GENDER_FEMALE = 1
    GENDER_CHOICES = [(GENDER_MALE, 'Male'), (GENDER_FEMALE, 'Female')]
    gender = models.IntegerField(choices=GENDER_CHOICES)
    MSTATE_single = 0
    MSTATE_MARRIED= 1
    MSTATE_CHOICES = [(MSTATE_single, 'single'),(MSTATE_MARRIED, 'Married')]
    Mstate = models.IntegerField(choices=MSTATE_CHOICES)
    
    
    
    def str(self):
        return self.empname
        
