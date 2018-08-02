/**
  ******************************************************************************
  * @file    LwIP/LwIP_HTTP_Server_Socket_RTOS/Src/httpserver-socket.c
  * @author  MCD Application Team
  * @brief   Basic http server implementation using LwIP socket API   
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes  -----------------------------------------------------------------*/
#include "lwip/sys.h"
#include "lwip/sockets.h"
#include "fs.h"
//#include "string.h"
#include "httpserver-socket.h"
//#include "cmsis_os.h"
/////////////////////////////
#include <string.h>
#include <stdlib.h>
////////////////////////////


#include <stdio.h>




/**
  * @brief serve tcp connection  
  * @param conn: connection socket 
  * @retval None
  */
void http_server_serve(int conn) 
{
  int buflen = 512;
  int ret;
  struct fs_file *file;
  unsigned char recv_buffer[512];
				
  /* Read in the request */
  ret = lwip_read(conn, recv_buffer, buflen);
  if(ret < 0) return;

  /* Check if request to get ST.gif */
  if (strncmp((char *)recv_buffer,"GET /STM32F4xx_files/ST.gif",27)==0)
  {
      file=fs_open("/STM32F4xx_files/ST.gif");
   lwip_write(conn, (const unsigned char*)(file->data), (size_t)file->len);
    fs_close(file);
  }
  /* Check if request to get stm32.jpeg */
  else if (strncmp((char *)recv_buffer,"GET /STM32F4xx_files/stm32.jpg",30)==0)
  {
      file=fs_open("/STM32F4xx_files/stm32.jpg");
      lwip_write(conn, (const unsigned char*)(file->data), (size_t)file->len);
    fs_close(file);
  }
  /* Check if request to get ST logo.jpeg */
  else if (strncmp((char *)recv_buffer,"GET /STM32F4xx_files/logo.jpg", 29) == 0)
  {
      file=fs_open("/STM32F4xx_files/logo.jpg");
      lwip_write(conn, (const unsigned char*)(file->data), (size_t)file->len);
    fs_close(file);
  }

  else if((strncmp((char *)recv_buffer, "GET /STM32F4xx.html", 19) == 0)||(strncmp((char *)recv_buffer, "GET / ", 6) == 0))
  {
    /* Load STM32F4xx */
      file=fs_open("/STM32F4xx.html");
      lwip_write(conn, (const unsigned char*)(file->data), (size_t)file->len);
    fs_close(file);
  }
  else
  {
    /* Load 404 page */
      file=fs_open("/404.html");
      lwip_write(conn, (const unsigned char*)(file->data), (size_t)file->len);
    fs_close(file);
  }
  /* Close connection socket */
  lwip_close(conn);
}

/**
  * @brief  http server thread 
  * @param arg: pointer on argument(not used here) 
  * @retval None
  */
static void http_server_socket_thread(void *arg)
{
  int sock, newconn, size;
  struct sockaddr_in address, remotehost;

 /* create a TCP socket */
  if ((sock = lwip_socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    return;
  }
  
  /* bind to port 80 at any interface */
  address.sin_family = AF_INET;
  address.sin_port = htons(80);
  address.sin_addr.s_addr = INADDR_ANY;

  if (lwip_bind(sock, (struct sockaddr *)&address, sizeof (address)) < 0)
  {
    return;
  }
  
  /* listen for incoming connections (TCP listen backlog = 5) */
  lwip_listen(sock, 5);
  
  size = sizeof(remotehost);
  
  while (1) 
  {
    newconn = lwip_accept(sock, (struct sockaddr *)&remotehost, (socklen_t *)&size);
    http_server_serve(newconn);
  }
}

/**
  * @brief  Initialize the HTTP server (start its thread) 
  * @param  none
  * @retval None
  */
void http_server_socket_init()
{
  sys_thread_new("http_server_socket", http_server_socket_thread, NULL, DEFAULT_THREAD_STACKSIZE, tskIDLE_PRIORITY + 2);
}

