// Date: 2019-11-30
/*==================[inlcusiones]============================================*/

#include "sapi.h"      // <= Biblioteca sAPI
/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

/*==================[funcion principal]======================================*/
   char dato  = 0;

int main (){
	   // ---------- CONFIGURACIONES ------------------------------
	   // Inicializar y configurar la plataforma
	   boardConfig();
	   uartConfig (UART_USB, 9600);
	   uartConfig (UART_232, 9600);
	  
	   printf( "Inicio exitoso: %d\r\n" );

	   while(1) {
		   uartWriteByte( UART_232, 'C' );  // Envia 'C'
	        // Si recibe un byte de la UART_USB lo guardarlo en la variable dato.
	        if(  uartReadByte( UART_232, &dato ) ){
	       // 	  uartWriteByte( UART_232, 'R' ); // Envia 'R'
	           // Se reenvia el dato a la UART_USB realizando un eco de lo que llega
	           uartWriteByte( UART_USB, dato );
	        }
     	    }
}
