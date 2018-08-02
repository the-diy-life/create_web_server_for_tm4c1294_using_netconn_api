
#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "fs.h"
#include <string.h>
#include <stdlib.h>
#include "httpd_structs.h"
#include "lwip/stats.h"
#include "httpserver-netconn.h"

#if LWIP_NETCONN

#ifndef HTTPD_DEBUG
#define HTTPD_DEBUG         LWIP_DBG_OFF
#endif



const static char http_html_hdr[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
const static char http_index_html[] = "<html><head><title>Congrats!</title></head><body><h1>Welcome to our lwIP HTTP server!</h1><p>This is a small test page, served by httpserver-netconn.</body></html>";

/** Serve one HTTP connection accepted in the http thread */
static void
http_server_netconn_serve(struct netconn *conn)
{
  struct netbuf *inbuf;
  char *buf;
  u16_t buflen;
  err_t err;
  struct fs_file *file;
  
  /* Read the data from the port, blocking if nothing yet there. 
   We assume the request (the part we care about) is in one netbuf */
  err = netconn_recv(conn, &inbuf);
  
  if (err == ERR_OK) {
	  if (netconn_err(conn) == ERR_OK)
	      {
    netbuf_data(inbuf, (void**)&buf, &buflen);
    
    if ((buflen >=5) && (strncmp(buf, "GET /", 5) == 0))
         {

    	 if((strncmp(buf, "GET /STM32F4xx.html", 19) == 0)||(strncmp(buf, "GET / ", 6) == 0))
    	           {
    	             file=fs_open("/STM32F4xx.html");
    	             netconn_write(conn, (const char*)(file->data), (size_t)file->len, NETCONN_NOCOPY);
    	             fs_close(file);
    	           }
          else if (strncmp((char const *)buf,"GET /STM32F4xx_files/logo.jpg", 29) == 0)
          {
             file=fs_open("/STM32F4xx_files/logo.jpg");
             netconn_write(conn, (const char*)(file->data), (size_t)file->len, NETCONN_NOCOPY);
             fs_close(file);
           }
          else if (strncmp((char const *)buf,"GET /STM32F4xx_files/ST.gif",27)==0)
           {
             file=fs_open("/STM32F4xx_files/ST.gif");
             netconn_write(conn, (const char*)(file->data), (size_t)file->len, NETCONN_NOCOPY);
             fs_close(file);
           }
          else if (strncmp((char const *)buf,"GET /STM32F4xx_files/stm32.jpg",30)==0)
                     {
                       file=fs_open("/STM32F4xx_files/stm32.jpg");
                       netconn_write(conn, (const char*)(file->data), (size_t)file->len, NETCONN_NOCOPY);
                       fs_close(file);
                     }
           else
                   {
                     /* Load Error page */
                     file=fs_open("/404.html");
                     netconn_write(conn, (const unsigned char*)(file->data), (size_t)file->len, NETCONN_NOCOPY);
                     fs_close(file);
                   }
         }
	      }
  }





  /* Close the connection (server closes in HTTP) */
  netconn_close(conn);
  
  /* Delete the buffer (netconn_recv gives us ownership,
   so we have to make sure to deallocate the buffer) */
  netbuf_delete(inbuf);
}

/** The main function, never returns! */

static void http_server_netconn_thread(void *arg)
{
  struct netconn *conn, *newconn;
  err_t err, accept_err;
  
  /* Create a new TCP connection handle */
  conn = netconn_new(NETCONN_TCP);
  
  if (conn!= NULL)
  {
    /* Bind to port 80 (HTTP) with default IP address */
    err = netconn_bind(conn, NULL, 80);

    if (err == ERR_OK)
    {
      /* Put the connection into LISTEN state */
      netconn_listen(conn);
  
      while(1)
      {

        /* accept any icoming connection */
        accept_err = netconn_accept(conn, &newconn);

        if(accept_err == ERR_OK)
        {

          /* serve connection */
        	http_server_netconn_serve(newconn);

          /* delete connection */
         netconn_delete(newconn);
        }
      }
    }
  }
}

/** Initialize the HTTP server (start its thread) */
void
http_server_netconn_init()
{
  sys_thread_new("http_server_netconn", http_server_netconn_thread, NULL, DEFAULT_THREAD_STACKSIZE, tskIDLE_PRIORITY + 2);
}

#endif /* LWIP_NETCONN*/
