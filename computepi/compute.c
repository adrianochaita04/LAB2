#include "compute.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* Number of hits */
unsigned int hits;

/* Mutex Semaphore */
pthread_mutex_t mutex;

/* Thread function */
void * thread_function(void * data) {
   /* The input variable contains the number of points that the thread must
    * calculate */
    int points = *((int *)data);    

    /* The local variable that shall be used to store the number of points within
     * the circular section */
    int count = 0;

    /* TODO: Implement the loop that obtains the random points and counts how
     * many of those lay within the circumference of radius 1 */

    double x;
    double y;
    struct drand48_data rand_buffer;         //Estructura drand48_data llamada rand_buffer(es utilizada para almacenar el estado interno del generador de números aleatorios drand48)
    srand48_r(time(NULL), &rand_buffer);     //Inicializa el generador de números aleatorios drand48
    for (int i = 0; i < points; i++){        
        drand48_r(&rand_buffer, &x);         //Genera un número aleatorio y el resultado se almacena en la variable x
        drand48_r(&rand_buffer, &y);         //Genera un número aleatorio y el resultado se almacena en la variable y
	if(x*x+y*y<=1){                      //Verifica si el punto (x, y) está dentro del círculo unitario y si esta dentro incrementa el contador 
		count ++;
	}
    }
    
    /* TODO: Add the count to the global variable hits in mutual exclusion */
    
    pthread_mutex_lock (&mutex);            //Bloquea el mutex, lo que significa que otros hilos que intentan adquirir el mismo mutex se bloquearán, se utiliza para garantizar la exclusión mutua
    hits = hits + count;	            
    pthread_mutex_unlock (&mutex);	    //Libera el mutex y esto permite que otros hilos adquieran el mutex y ejecuten su propia sección crítica
    
    return NULL;
}

void compute(int npoints, int nthreads) {

   /* TODO: Erase the following line: */
	/*printf("compute(%d, %d)\n", npoints, nthreads);  En el enunciado pone que lo borremos pero yo lo comento por si acaso*/
	
   /* TODO: Launch the threads that will count the points */
   
   pthread_mutex_init (&mutex, NULL);	   //Inicializa un mutex que se utiliza para garantizar la exclusión mutua en secciones críticas
   pthread_t p_thread[8];		   //Almacena los identificadores de los hilos creados posteriormente con capacidad para 8 elememtos
   	for (int i = 0; i<nthreads; i++){  
        	pthread_create(& p_thread[i], NULL,thread_function, (void*) &npoints);     //Se utiliza la función pthread_create para crear un nuevo hilo y diferentes argumentos
        }

   /* TODO: Wait for all threads to finish */
   
   int status;
    	for (int i = 0; i<nthreads; i++){  				//Bucle for que se repetirá nthreads veces, donde nthreads es que indica la cantidad de hilos que se deben crear
        	pthread_join(p_thread[i], (void **)&status);    //La función pthread_join espera a que el hilo con el identificador p_thread[i] complete su ejecución y tiene diferentes argumentos
        }
        
   /* TODO: print the ratio of points that meet the criteria */

   /* The following print string can be used to print the calculated value:
    * printf("%.8f\n", VALUE_OF_PI);
    * where VALUE_OF_PI is the floating-point value to be printed.
    */
    
    double radio = hits;
    radio = radio/npoints;
    radio = radio/nthreads;
    double pi = radio*4;                  //Multiplica radio por 4 para obtener una aproximación del valor de pi
	printf("Radio: %.8f\n", radio);
	printf("Pi(𝝅): %.8f\n", pi);
	pthread_mutex_destroy(&mutex);	  //Destruye el mutex (mutex) que se había inicializado anteriormente
}

