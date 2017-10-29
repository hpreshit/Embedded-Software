#ifndef INCLUDES_PROJECT2_H_
#define INCLUDES_PROJECT2_H_

#define NUM "Number of Numeric Characters       : "
#define ALPHA "Number of Alphabetic Characters    : "
#define PUNC "Number of Punctuation Characters   : "
#define MISC "Number of Miscellaneous Characters : "
#define TOTAL "Total number of Characters         : "

extern uint8_t character_count[5];
extern uint8_t Rx_Data;
extern uint8_t Tx_Data;
extern CB_t Tx_Buffer;
extern CB_t Rx_Buffer;


void Table_Stats_1();
void Table_Stats();
void project_2();

#endif /* INCLUDES_PROJECT2_H_ */
