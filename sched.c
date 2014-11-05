unsigned char table[8]={0,0,0,0,0,0,0,0};
unsigned char run_bit=0;


int task_create(unsigned int num, TCB *tcb)
{
	int n=0;

	for (n=0;n<num;n++){
		create_priority_table(tcb->priority);
		allocate_task(tcb);
		setup_context(tcb);
	}

	dispatch_init();
}


void create_priority_table(unsigned int priority)
{
	int table_index = priority/8;
	int bit_index = priority%8;
	table[table_index]| = 1<<bit_index
		run_bit|= 1<<bit_index;
}


void idle_task()
{
	while(1) 
	{
		enable_interrupts();
	}

}


/* Start with idle_task */

void dispatch_init()
{
context_switch_half(&idle_task);
}

