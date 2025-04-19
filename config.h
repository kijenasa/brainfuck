#define ASSEMBLE(program) system("as -o" program ".o " program ".s")
#define LINK(program) system("ld -o " program " " program " .o")
