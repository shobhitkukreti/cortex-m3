#include "sys.h"

unsigned char table[8]={0,0,0,0,0,0,0,0};
unsigned char run_bit=0;

void runlist_init()
{
	int i=0;
	for(i=0;i<MAX_TASK;i++)
		run_list[i] = (TCB*)0;

	for(i=0;i<8;i++)
		table[i]=0;
	run_bit=0;
}


void runqueue_add(TCB *tcb, uint8_t priority)
{
        uint8_t table_index = priority/8;
        uint8_t bit_index = priority%8;
        table[table_index] |= 1<<bit_index;
        run_bit |= 1<<table_index;
	run_list[priority]=tcb;
}


void runqueue_remove(TCB *tcb, uint8_t priority,uint8_t list_id) {

	uint8_t table_index = priority/8;
	uint8_t bit_index = priority%8;

	table[table_index] &= ~(1<<bit_index);
	run_bit &= ~(1<<table_index);
	if(list_id)
		run_list[priority]=tcb;
	else
		sleep_list[priority]=tcb;

}


/* Needs Better implementation */
uint8_t next_highest_prio() {
	int cnt=0,ti=0,bi=0,tmp = run_bit;
	unsigned int prio=0;
	while(cnt<8)
	{
		if(tmp&0x01)
			break;
		else {
			tmp=tmp>>1;
			cnt++;
		}
	}
	ti=cnt;// table index found
	tmp = table[cnt];
	cnt=0;
	while(cnt<8) {
		if(tmp&0x01) break;
		else {
			tmp=tmp>>1;
			cnt++;
		}
	}
	bi=cnt; // bit index found

	prio = (2<<ti)+bi;
}
