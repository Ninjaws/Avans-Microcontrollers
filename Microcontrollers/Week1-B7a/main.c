/*
 * T1B7A.c
 *
 * Created: 30-1-2019 15:24:21
 * Author : Max & Daan
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

// prototypes
void s1(void);
void s2(void);
void s3(void);
void end(void);
void start(void);

//enums
typedef enum { D7, D6, D5 } ENUM_EVENTS;
typedef enum { START, STATE_1, STATE_2, STATE_3, END } ENUM_STATES;


typedef struct {
	void (*finit)(void);
	void (*fbody)(void);
	void (*fexit)(void);
	ENUM_STATES nextState;
} STATE_TRANSITION_STRUCT;


STATE_TRANSITION_STRUCT fsm[5][3] = {
	{ {s1,   NULL,  NULL, START}, 	{NULL, s1, NULL, STATE_1},		{NULL, s2, NULL, STATE_2} },
	{ {NULL, start, NULL, START},	{NULL, NULL, NULL, STATE_1},	{NULL, s2, NULL, STATE_2} },
	{ {NULL, start, NULL, START}, 	{NULL, s1, NULL, STATE_1}, 		{NULL, s3, NULL, STATE_3} },
	{ {NULL, NULL,  NULL, START},	{NULL, end, NULL, END}, 		{NULL, end, NULL, END} },
	{ {NULL, start, NULL, START},	{NULL, end, NULL, END}, 		{NULL, end, NULL, END} }
};

ENUM_STATES state = START;

void handleEvent(ENUM_EVENTS event)
{
	
	if( fsm[state][event].fexit != NULL) {
		fsm[state][event].fexit() ;
	}
	
	state = fsm[state][event].nextState;

	if( fsm[state][event].finit != NULL) {
		fsm[state][event].finit() ;
	}

	if( fsm[state][event].fbody != NULL) {
		fsm[state][event].fbody() ;
	}
}


void s1(void){
	printf("s1\n");
}

void s2(void){
	printf("s2\n");
}

void s3(void){	
	printf("s3\n");
}

void start(void){
	printf("start\n");
}

void end(void){	
	printf("end\n");
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		
	}
}

int main( void )
{
	
	DDRD = 0b00001111;		 
	
	// Test
	handleEvent(D6);
	handleEvent(D5);
	handleEvent(D5);

	while (1)
	{
	}

	return 1;
}