#include "config.h"

#ifdef X86_64_LINUX

#define HEADER_ASM                                                                                                     \
    ".intel_syntax noprefix\n \
.global _start\n\n \
_start:\n"

#define STACK_INIT_ASM                                                                                                 \
    "# STACK_INIT_ASM\n \
    sub rsp, 30000\n \
    mov rbx, rsp\n"
#define STACK_CLEAN_ASM                                                                                                \
    "# STACK_CLEAN_ASM\n \
    add rsp, 30000\n"

#define EXIT_ASM                                                                                                       \
    "# EXIT_ASM\n \
    mov rax, 60\n \
    mov rdi, 0\n \
    syscall\n\n"

#define POINTER_INCREMENT_ASM                                                                                          \
    "# POINTER_INCREMENT_ASM\n \
    sub rbx, 1\n"
#define POINTER_DECREMENT_ASM                                                                                          \
    "# POINTER_DECREMENT_ASM\n \
    add rbx, 1\n"

#define CELL_INCREMENT_ASM                                                                                             \
    "# CELL_INCREMENT_ASM\n \
    add byte ptr [rbx], 1\n"
#define CELL_DECREMENT_ASM                                                                                             \
    "# CELL_DECREMENT_ASM\n \
    sub byte ptr [rbx], 1\n"

#define CELL_OUTPUT_ASM                                                                                                \
    "# CELL_OUTPUT_ASM\n \
    mov rax, 1\n \
    mov rdi, 1\n \
    mov rsi, rbx\n \
    mov rdx, 1\n"
#define CELL_INPUT_ASM                                                                                                 \
    "# CELL_INPUT_ASM\n \
    mov rax, 0\n \
    mov rdi, 1\n \
    mov rsi, rbx\n \
    mov rdx, 1\n"

#define JUMP_OPEN_ASM "\n"
#define JUMP_CLOSE_ASM "cmp byte ptr [rsp], 0\n"
//    je %s\n"

#endif
