# Create  web server Using FreeRTOS and LWIP netconn API in tm4c1294 connected launchpad 



## Getting Started

These instructions will give details on how to create simple WEB SERVER using FreeRTOS and LWIP netconn API in tm4c1294 connected launchpad. we will use the example project enet.io which presented by TIVAWARE that can be found in (C:\ti\TivaWare_C_Series-2.1.4.178\examples\boards\ek-tm4c1294xl\enet_io ). this project is running using LWIP RAW API without using any RTOS so we will include FreeRTOS in that project and then create some files to establish the netconn API task  

## Prerequisites
same as we did in [test-gpio project](https://github.com/ahosny333/test-gpio)
> 1- Download and install the latest version of Code Composer Studio (CCS) and TivaWare as we described [here](https://github.com/ahosny333/test-gpio/blob/master/README.md)
 
> 2-Download and install the latest full version of FreeRTOS source code from [here](https://www.freertos.org/a00104.html)
 we are using in this project FreeRTOSv10.0.1



## Initialize code composer studio
same as we did in [test-gpio project](https://github.com/ahosny333/test-gpio)
> 1- in code composer open the exist project C:\ti\TivaWare_C_Series-2.1.4.178\examples\boards\ek-tm4c1294xl\enet_io 
 
> 2- build variables for the paths that CCS will need to find your files.

> 3- Link driverlib.lib to Your Project

> 4- Add the INCLUDE search paths for the header files

> 5- Include FreeRTOS files into project as we described [here](https://github.com/ahosny333/free_RTOS_template_for_tm4c1294)

## Modify the project files to use netconn API 

> 1- in lwipots.h edit NO_SYS to be 0 and edit LWIP_NETCONN to be 1

	#define NO_SYS                         0
	#define LWIP_NETCONN                   1 

> 2- in lwipopts.h add the two lines 

	#define RTOS_FREERTOS					1
	#define LWIP_COMPAT_MUTEX               1


> 3- in opt.h file edit the following 

	#define TCPIP_THREAD_STACKSIZE          1000
	#define TCPIP_MBOX_SIZE                 6
	#define DEFAULT_THREAD_STACKSIZE        1000
	#define DEFAULT_UDP_RECVMBOX_SIZE       6
	#define DEFAULT_TCP_RECVMBOX_SIZE       6
	#define DEFAULT_ACCEPTMBOX_SIZE         6

> 4- in sys_arch.h add the follwoing definition which we will use to add some functions in sys_arch.c
	
	#define SYS_SEM_NULL       0
	
> 5- in sys_arch.c add the following functions

	int sys_sem_valid(sys_sem_t *sem)
	{
	if (sem->queue == SYS_SEM_NULL)
    return 0;
	else
    return 1;
	}

	void sys_sem_set_invalid(sys_sem_t *sem)
	{
	sem->queue = SYS_SEM_NULL;
	}
	
	void sys_mbox_set_invalid(sys_mbox_t *mbox)
	{
	mbox->queue = SYS_MBOX_NULL;
	}

> 5- in sys_arch.c remove the folllowing lines while these lines make limited numbers of the used semaphores and mail boxes

	sems[i].queue = sem->queue;
    mboxes[i].queue = mbox->queue;

> 6- add and include the created server files httpserver\_netconn.c and httpserver\_netconn.h which create the netconn server task   

> 7- in the enet_io.c file 

  > * include httpserver_netconn.h
  > * in the main function call the following function to initialize the netconn task
  
	http_server_netconn_init(); instead of httpd\_init();
	
  > * add the scheduller funcion vTaskStartScheduler()
  > * remove the timer interrupt handler SysTickIntHandler and its configuration functions as this interrupt is used only in case of RAW API 
	
> 8- in this project we did not use HTTPD dynamic headers so we use custom data files in io_fsdata.h instead of files used in original project 

## Sponsored by
<a href = "https://the-diy-life.co">
<img src="https://the-diy-life.co/images/logo_diylife.jpg"  width="248" height="248">
</a>

