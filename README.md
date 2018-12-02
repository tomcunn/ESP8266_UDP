# ESP8266_UDP
Playing around with UDP

Had two clients recieving data over UDP. I played around with TCP, but do not like the connections aspect to it because it requires
a connection period at the beginning of the code, or using threads to manage new incoming connections.

UDP appears to be dumb, which I like. I can have clients connect at any point and it just works. Without connections though there is no 
way to know if anyone is listening but that can be managed with some acknowledgements.

I also liked that udp.parsePacket(); is non blocking. My testing showed that it took around 27ms to execute. This is fine for most of my 
applications. 
