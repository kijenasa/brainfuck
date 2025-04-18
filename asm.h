#define HEADER_ASM                                                                                                     \
    ".intel_syntax noprefix \
    .global _start \
    _start:\n"

#define STACK_INIT_ASM                                                                                                 \
    "sub rsp, 30000 \
    mov rbx, rsp\n"
#define STACK_CLEAN_ASM "add rsp, 30000\n"

#define EXIT_ASM                                                                                                       \
    "mov rax, 60 \
    mov rdi, 0 \
    syscall\n"

#define POINTER_INCREMENT_ASM "sub rbx, 1\n"
#define POINTER_DECREMENT_ASM "add rbx, 1\n"
#define CELL_INCREMENT_ASM "add [rbx], 1\n"
#define CELL_DECREMENT_ASM "sub [rbx], 1\n"
#define CELL_OUTPUT_ASM ""
#define CELL_INPUT_ASM ""
#define JUMP_OPEN_ASM ".%s:\n"
#define JUMP_CLOSE_ASM                                                                                                 \
    "cmp [rsp], 0 \
    je %s\n"
