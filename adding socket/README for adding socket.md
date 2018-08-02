# Create  web server Using FreeRTOS and LWIP socket API in tm4c1294 connected launchpad 



## Getting Started

These instructions will give details on how to edit our project to use socket API instead of netconn API to create simple WEB SERVER using FreeRTOS and LWIP socket API in tm4c1294 connected launchpad.




## Modify our [netconn server project](https://github.com/ahosny333/webserver_using_freertos_netconn_lwip) files to use socket API 

> 1- in lwipots.h edit the following lines to include lwip socket

	#define LWIP_SOCKET                       1         // default is 1
	#define LWIP_COMPAT_SOCKETS               0
	
> 2- in lwipopts.h add the following definition to include errorno.h file

	#define LWIP_PROVIDE_ERRNO                1

> 3- add and include into our project the created server files httpserver\_socket.c and httpserver\_socket.h which create the socket server task   

> 4- add into our project errorno.h file which include error defines and then include that file into httpserver\_socket.h

> 5- in the enet_io.c file 

  > * include httpserver_socket.h
  > * in the main function call the following function to create and initialize lwip socket task
  
	    http_server_socket_init(); instead of http_server_netconn_init();
	
	



