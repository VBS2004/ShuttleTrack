from django.shortcuts import render,redirect
from django.contrib import messages
import folium
import socket
import os
from threading import Thread
latlong=0
def connectf():
        global c
        c=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        try:
            c.connect(("127.0.0.1",5000))
        except:
            connectf()
def devil_socket():
    global c
    global latlong
    try:
        try:
            latlong=c.recv(6000).decode("utf-8")
        except:
            devil_socket()
    except:
        devil_socket()
        

# Create your views here.
def say_hello(request):
    global latlong
    connectf()
    # Make an empty map
    while 1:
        devil_socket()
        latlong=list(map(float,latlong.split(",")))
        m = folium.Map(location=[12.9692,79.1559], tiles="OpenStreetMap", zoom_start=15)
        folium.Marker(latlong).add_to(m)
        m=m._repr_html_()
        context={
            "m":m
        }
        return render(request, 'hello.html',context)

            
