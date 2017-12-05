/*
 * logger.c

 *
 *  Created on: 03-Dec-2017
 *      Author: defaultuser0
 */

#include "logger.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t test_payload[10] = "abc cde ef";

Log_t log_buffer;
uint8_t Log_Tx_Data;

uint8_t log_tag[18][26] = 		   {"<LOG INITIALIZED>",
									"<GPIO INITIALIZED>",
									"<SYSTEM INITIALIZED>",
									"<SYSTEM HALTED>",
									"<INFO>",
									"<WARNING>",
									"<ERROR>",
									"<PROFILING STARTED>",
									"<PROFILING RESULT>",
									"<PROFILING COMPLETED>",
									"<DATA RECIEVED>",
									"<DATA ANALYSIS STARTED>",
									"<DATA ALPHA COUNT>",
									"<DATA NUMERIC COUNT>",
									"<DATA PUNCTUATION COUNT>",
									"<DATA MISC COUNT>",
									"<DATA ANALYSIS COMPLETED>",
									"<HEARTBEAT>"};

void log_pass(Log_Status id0,uint8_t *log_payload, uint8_t length){

	//START_CRITICAL();
	Log_Struct log_struct;
	log_struct.log_id0 = id0;
	log_struct.timestamp = RTC->TSR;
	log_struct.payload = log_payload;
	log_struct.len_payload = length;

	log_item(&log_struct);
	//END_CRITICAL();
	//log_flag = 0x78;

}

void log_flush(void){
	while(Log_buffer_is_empty(&log_buffer) != LOG_BUFFER_EMPTY){
		Log_buffer_remove_item(&log_buffer, &Log_Tx_Data);
		UART_send(&Log_Tx_Data);
	}

}

void log_id(Log_Status id){
	switch(id){
		case LOG_INITIALIZED:
			log_pass(LOG_INITIALIZED,test_payload,10);
			if(uart_flag != 0x43){
			log_flush();}
		    break;
		case GPIO_INITIALIZED:
          break;

		case SYSTEM_INITIALIZED:
			log_pass(SYSTEM_INITIALIZED,NULL,0);
			if(uart_flag != 0x43){
				log_flush();}
             break;

		case SYSTEM_HALTED:
			log_pass(SYSTEM_HALTED,NULL,0);
			if(uart_flag != 0x43){
				log_flush();}

			break;
		case INFO:
			break;
		case WARNING:
			break;
		case ERROR:
			break;
		case PROFILING_STARTED:
			break;
		case PROFILING_RESULT:
			break;
		case PROFILING_COMPLETED:
			break;
		case DATA_RECIEVED:
			break;
		case DATA_ANALYSIS_STARTED:
			break;
		case DATA_ALPHA_COUNT:
			break;
		case DATA_NUMERIC_COUNT:
			break;
		case DATA_PUNCTUATION_COUNT:
			break;
		case DATA_MISC_COUNT:
			break;
		case DATA_ANALYSIS_COMPLETED:
			break;
		case HEARTBEAT:
			//START_CRITICAL();
			log_pass(HEARTBEAT,NULL,0);
			if(uart_flag != 0x43){
			log_flush();}
			//END_CRITICAL();
            break;
		default:
             break;

	}
}

void log_item(Log_Struct *ab){

	uint8_t buffer[80];

	my_itoa(ab->timestamp,buffer,10);
	uint8_t i = 1;
			while(buffer[i] != 0){
				Log_buffer_add_item(&log_buffer, &buffer[i]);
				i++;
				buffer[i-1] = 0;
			}
	i=' ';
	Log_buffer_add_item(&log_buffer,&i);
	uint8_t y;
	y = 0;
	y = (uint8_t)(ab->log_id0);
	my_itoa(y,buffer,10);

	i = '\t';
		Log_buffer_add_item(&log_buffer,&i);

	i = 0;
		while(log_tag[y-100][i] != 0){
			Log_buffer_add_item(&log_buffer, &log_tag[y-100][i]);
			i++;
		}
	i = '\t';
	Log_buffer_add_item(&log_buffer,&i);


	i = 1;
		while(buffer[i] != 0){
			Log_buffer_add_item(&log_buffer, &buffer[i]);
			i++;
			buffer[i-1] = 0;
		}

	//Log_buffer_add_item(&log_buffer, &bu);

	i=' ';
	Log_buffer_add_item(&log_buffer,&i);

	if(ab->payload != NULL){
		my_itoa(ab->len_payload,buffer,10);
		i=1;
		while(buffer[i] != 0){
		Log_buffer_add_item(&log_buffer, &buffer[i]);
		i++;
		//buffer[i-1] = 0;
		}
		for(i=0;i<ab->len_payload;i++){
			Log_buffer_add_item(&log_buffer,ab->payload +i);
		}
	}
	i='\r';
	Log_buffer_add_item(&log_buffer,&i);
	i='\n';
	Log_buffer_add_item(&log_buffer,&i);
	i='\r';
	Log_buffer_add_item(&log_buffer,&i);
	i='\n';
	Log_buffer_add_item(&log_buffer,&i);


}

void log_string(uint8_t *str){
	uint8_t d;
	while(*str != 0){
		d = *str;
		UART_send(&d);
		str++;
	}
}

void log_data(uint8_t *data, uint8_t length){
	uint8_t i = 0,l;
	while(i<length){
		l = *(data + i);
		UART_send(&l);
		i++;
	}
}

void log_int(int32_t num){
	uint8_t buffer[20];
	uint8_t o = 1;
	my_itoa(num,buffer,10);
	while(buffer[o] != 0){
		UART_send(&buffer[o]);
		o++;
		buffer[o-1] = 0;
	}
}


