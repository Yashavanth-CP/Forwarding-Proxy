Forwarding-Proxy
================

Hello..
 
I started working on implementing  a simple forwarding proxy  module.
Its similiar to Squid and Nginx, but it wont intercept the packets 
as of now (just do forwarding) 

1. Listen on some ports, configured in the configuartion file.
2. Accept the connection and create a new connection to the original server address,
   using the proxy machine address(May be tproxy functionality can be supported in Future)
3. Using C++11 standard in order to get comfortable.
4. Completely written in C++
5. Using epoll -- Aynchronous system call.
6. Big project -- May take some time and would like to do it incrementally.
   STAY Tuned!!!




       ----------    Downlink         -----------  Uplink             -----------
      |          |       Connection  |           |      Connection   |           |
      |          |-----------------> |           |-----------------> |           |
      |          |                   | FORWARDING|                   |ORIGIN     |
      |  CLIENT  |                   | PROXY     |                   |   SERVER  |
      |          |<----------------- |           |<----------------- |           |
      |          |                   |           |                   |           |
      |          |                   |           |                   |           |
       ----------                     -----------                     -----------
