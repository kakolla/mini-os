

// typedefs rename
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef uint32_t size_t;


// external link to defined symobls
extern uint8_t __bss[];
extern uint8_t __bss_end[];
extern uint8_t __stack_top_addr[];


// set contiguous section in memory of size n to only 'c' 
void* memset(void* buf, char c, size_t n) {
	uint8_t* start_ptr = (uint8_t*) buf;
	while (n--) {
		*start_ptr = c;
		start_ptr++; 
	}
	return start_ptr;
}




void kernel_main(void) {
	size_t bss_init_size =  __bss_end - __bss;
	memset(__bss, 0, bss_init_size); // zero out bss section
	

	for (;;) {
	}
}



// gcc C attributes for the compiler
__attribute__((section(".text.boot")))
__attribute__((naked)) // dont insert other asm here
void boot(void) {
	__asm__ __volatile__(
		"mv sp, %[stack_top]\n"
		"j kernel_main\n" // jump 
		: // no output variables
		: [stack_top] "r" (__stack_top_addr)
	);
		
}



