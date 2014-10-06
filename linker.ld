
ENTRY(Reset_Handler)

MEMORY
{
flash (rx) : ORIGIN = 0x00000000, LENGTH = 256K
ram  (rwx) : ORIGIN = 0x20000000, LENGTH =  64K
}

vTopRam = ORIGIN(ram) + LENGTH(ram);

SECTIONS

{
.text :
{
     . = ALIGN(4);
     *(.isrvectors)
     *(.text)
     *(.rodata)
     *(.rodata*)
     . = ALIGN(4);
     _endflash = .;
} > flash


.data :
{
     . = ALIGN(4);
     _start_data = .;
     *(vtable)
     *(.data)
     . = ALIGN(4);
     _end_data = .;
} >  ram AT > flash

.bss :
{
     . = ALIGN(4);
     _start_bss = .;
     *(.bss)
     *(COMMON)
     . = ALIGN(4);
     _end_bss = .;
 } >  ram

}




