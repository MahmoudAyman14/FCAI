from django.contrib import admin
from django.urls import path, include
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from django.conf import settings
from django.conf.urls.static import static
from . import views
urlpatterns = [
    path('admin/', admin.site.urls),
    path('getVacations',views.getVacations,name='getVacations'),
    path('getaccVacations',views.getaccVacations,name='getaccVacations'),
    path('addemployee',views.addemployee,name='addemployee'),
    path('searchemployee',views.searchemployee,name='searchemployee'),
    path('submitvac',views.submitvac,name='submitvac'),
    path('acceptvac',views.acceptvac,name='acceptvac'),
    path('deletevac',views.deletevac,name='deletevac'),
    path('deleteemployee',views.deleteemployee,name='deleteemployee'),
    
]