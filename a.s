.intel_syntax noprefix
     .global _start
     _start:
# STACK_INIT_ASM
     sub rsp, 30000
     mov rbx, rsp
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
.label_temp:
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
cmp [rsp], 0
     je label_temp
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
.label_temp:
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
cmp [rsp], 0
     je label_temp
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
.label_temp:
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
cmp [rsp], 0
     je label_temp
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
.label_temp:
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
cmp [rsp], 0
     je label_temp
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_OUTPUT_ASM
     mov rax, 1
     mov rdi, 1
     mov rsi, rbx
     mov rdx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
.label_temp:
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# CELL_INCREMENT_ASM
     add [rbx], 1
# POINTER_INCREMENT_ASM
     sub rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
cmp [rsp], 0
     je label_temp
# POINTER_DECREMENT_ASM
     add rbx, 1
# CELL_INCREMENT_ASM
     add [rbx], 1
