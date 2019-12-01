#include "sapi.h"      // <= Biblioteca sAPI
int main (){
	   // ---------- CONFIGURACIONES ------------------------------
	   // Inicializar y configurar la plataforma
	   boardConfig();
	   uartConfig (UART_USB, 9600);
	   uartConfig (UART_232, 9600);
  
	   waitForReceiveStringOrTimeout_t waitText;
                 waitForReceiveStringOrTimeoutState_t waitTextState;

	   printf( "Inicio exitoso:\r\n" );

	   char dato[]=" ";
	   char recibirhastafindelinea[] = "\r\n";
	   uint32_t size =115;
	   uint32_t *tamanio= &size;

	   while(1) {

		   waitTextState = UART_RECEIVE_STRING_CONFIG;
		   waitText.state = UART_RECEIVE_STRING_CONFIG;
		   waitText.string =  recibirhastafindelinea;
		   waitText.stringSize = sizeof(recibirhastafindelinea);
		   waitText.timeout = 10000;

		  uartWriteByte( UART_232, 'C' );  // Envia 'C' para que empiece modo de transmision continuo

		 if (receiveBytesUntilReceiveStringOrTimeout( UART_232, &waitText , &dato, *tamanio )){

           // Se reenvia el dato a la UART_USB realizando un eco de lo que llega
 
	     uartWriteByte( UART_USB, dato );
	     uartWriteByte( UART_232, 'r' );  // Envia 'r' para detener transimision
	    
	        }
	        }
	     }
