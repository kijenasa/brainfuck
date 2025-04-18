#define HEADER_ASM                                                                                                     \
    ".intel_syntax noprefix \
    .global _start \
    _start:\n"

#define STACK_INIT_ASM                                                                                                 \
    "# STACK_INIT_ASM \
    sub rsp, 30000 \
    mov rbx, rsp\n"
#define STACK_CLEAN_ASM                                                                                                \
    "# STACK_CLEAN_ASM \
    add rsp, 30000\n"

#define EXIT_ASM                                                                                                       \
    "# EXIT_ASM \
    mov rax, 60 \
    mov rdi, 0 \
    syscall\n"

#define POINTER_INCREMENT_ASM                                                                                          \
    "# POINTER_INCREMENT_ASM \
    sub rbx, 1\n"

#define POINTER_DECREMENT_ASM                                                                                          \
    "# POINTER_DECREMENT_ASM \
    add rbx, 1\n"
#define CELL_INCREMENT_ASM                                                                                             \
    "# CELL_INCREMENT_ASM \
    add [rbx], 1\n"
#define CELL_DECREMENT_ASM                                                                                             \
    "# CELL_DECREMENT_ASM \
    sub [rbx], 1\n"
#define CELL_OUTPUT_ASM                                                                                                \
    "# CELL_OUTPUT_ASM \
    mov rax, 1 \
    mov rdi, 1 \
    mov rsi, rbx \
    mov rdx, 1\n"
#define CELL_INPUT_ASM                                                                                                 \
    "# CELL_INPUT_ASM \
    mov rax, 0 \
    mov rdi, 1 \
    mov rsi, rbx \
    mov rdx, 1\n"

#define JUMP_OPEN_ASM ".%s:\n"
#define JUMP_CLOSE_ASM                                                                                                 \
    "cmp [rsp], 0 \
    je %s\n"
