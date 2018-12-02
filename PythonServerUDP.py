#!/usr/bin/env python

import socket
import time


UDP_IP = '192.168.0.173'
UDP_PORT = 10000
BUFFER_SIZE = 3  # Normally 1024, but we want fast response
data_to_send = bytearray(b'\x65\x66\x67\x68')
data_to_send2 = bytearray(b'\x64\x66\x67\x69')
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((UDP_IP, UDP_PORT))
print('UDP Server is running')

while (True):
   s.sendto(data_to_send, ("192.168.0.122",10000))
   s.sendto(data_to_send2, ("192.168.0.161",10000))
   print("data sent")
   time.sleep(5)
