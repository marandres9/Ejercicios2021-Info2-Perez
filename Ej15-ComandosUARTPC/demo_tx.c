
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"



int main()
{
  int i=0,
      cport_nr=2,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */

  int cantBytes;
  unsigned char recibidos[1024];

  char mode[]={'8','N','1',0},
       str[2][512];


  strcpy(str[0], "A");

  strcpy(str[1], "E");

  if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
  {
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
    RS232_cputs(cport_nr, str[i]);
    Sleep(200);
    cantBytes = RS232_PollComport(cport_nr, recibidos, 1023);
    recibidos[cantBytes] = 0;
    printf("sent: %s, cantidad: %d\n", str[i], cantBytes);

    #ifdef _WIN32
        Sleep(2000);
    #else
        usleep(1000000);  /* sleep for 1 Second */
    #endif

    i++;  // para cambiar el str q muestra

    i %= 2; // cuando i=2 el rdo es 0
  }

  return(0);
}

