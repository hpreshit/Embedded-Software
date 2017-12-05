/*
 * logger.h
 *
 *  Created on: 03-Dec-2017
 *      Author: defaultuser0
 */

#ifndef SOURCES_LOGGER_H_
#define SOURCES_LOGGER_H_

#include <stdint.h>
#include "MKL25Z4.h"
#include <stdlib.h>
#include "logbuf.h"
#include "uart.h"
#include "conversion.h"


#define LOG(id)							(log_id(id))
#define LOG_DATA(data,length)			(log_data(*data,length))
#define LOG_STRING(str)					(log_string(*str))
#define LOG_INT(num)					(log_int(num))
#define LOG_FLUSH()						(log_flush())

#define START_CRITICAL()				(__disable_irq())
#define END_CRITICAL()					(__enable_irq())

extern Log_t log_buffer;
extern uint8_t Log_Tx_Data;

typedef enum{
	LOG_INITIALIZED = 100,
	GPIO_INITIALIZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECIEVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED,
	HEARTBEAT
}Log_Status;

typedef struct{

	Log_Status log_id0;
	uint32_t timestamp;
	uint16_t len_payload;
	uint8_t *payload;
	uint16_t checksum;

}Log_Struct;


void log_pass(Log_Status id0,uint8_t *log_payload, uint8_t length);
void log_id(Log_Status id);
void log_item(Log_Struct *ab);
void log_flush(void);
void log_string(uint8_t *str);
void log_data(uint8_t *data, uint8_t length);
void log_int(int32_t num);



#endif /* SOURCES_LOGGER_H_ */
