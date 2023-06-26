from django.contrib import admin
from django.urls import path, include
from .import views
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
urlpatterns = [
    path('admin/', admin.site.urls),
    path('',views.homepage,),
    path('home/',views.home,name='Home'),
    path('search/',views.search,name='search'),
    path('submitted vacations/',views.submittedvacations,name='submitted vacations'),
    path('update an existing employee/',views.updateanexistingemployee,name='update an existing employee'),
    path('vacation form/',views.vacationform,name='vacation form'),
    path('vacations/',views.vacations,name= 'vacations'),
    path('add a new employee/',views.addanewemployee,name='add a new employee'),
    path('edit employee data/',views.editemployeedata,name='edit employee data'),
    path('database/',include('database.urls')),
]

urlpatterns += staticfiles_urlpatterns()