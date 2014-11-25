#include<stdio.h>
#include <stdint.h>
// Packet is 7 bytes long.
#define PCKLEN 7

// Global Data extracted from Report
unsigned glb_TSMP=0;
unsigned type=0;
uint16_t mdeltax=0;
uint16_t mdeltay=0;
uint8_t btn_l;
uint8_t btn_r;

uint8_t ERROR=0;

void handleReport(uint8_t *buffer, uint16_t len) {


	unsigned c_time=0, prev_time=0,tmp_t=0;
	uint16_t tmp_dx=0,tmp_dy=0;
	
	// Error Checking
	// Discard packets if len < 7
	if(len!=7) {
		ERROR=1; // Handle Error
	}
	else {
		type=*buffer++; // B0
		buffer++; // Ignore the reserved byte
		mdeltax=*buffer++; // B2
		mdeltay=*buffer++; // B3
		btn_r= (*buffer) & 0x01; //B4
		btn_l = (((*buffer)>>1) & 0x01);
		tmp_dx = (uint16_t)(*buffer) & 0x0C;
		mdeltax |= tmp_dx << 6;
		tmp_dy = (uint16_t)(*buffer) & 0x30;
		mdeltay |=tmp_dy<<6;
		c_time |= ((*buffer) & 0xc0) >> 6;
		tmp_t =  *buffer++; // B5
		c_time |= tmp_t <<8;
		tmp_t = *buffer++; // B6
		c_time |= tmp_t << 16;

	if(c_time > prev_time) {// current_time > prev_time
		glb_TSMP+=c_time;
		prev_time=c_time;
	}
	else // roll over condition
	{
		glb_TSMP+=(0X3FFFF-prev_time) + c_time;
		prev_time = c_time;
	}
} 
}
