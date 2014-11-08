#include "sys.h"



void create_priority_table(unsigned int priority)
{
        int table_index = priority/8;
        int bit_index = priority%8;
        table[table_index]| = 1<<bit_index
                run_bit|= 1<<bit_index;
}

