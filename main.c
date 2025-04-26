#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "asm.h"
#include "config.h"

enum instruction {
    SKIP,
    PROGRAM_START,
    POINTER_INCREMENT,
    POINTER_DECREMENT,
    CELL_INCREMENT,
    CELL_DECREMENT,
    CELL_OUTPUT,
    CELL_INPUT,
    JUMP_OPEN,
    JUMP_CLOSE,
    PROGRAM_END,
};

unsigned int label_stack[LABEL_STACK_SIZE] = {0};
unsigned int label_stack_pointer = 0;
int label_next = 0;

/* Lexer */

int get_program_length(const char *program) {
    int len = 0;
    for(int i = 0; i < (int)strlen(program); i++) {
        switch(program[i]) {
        case '>':
        case '<':
        case '+':
        case '-':
        case '.':
        case ',':
        case '[':
        case ']':
            len++;
        }
    }

    return len;
}

enum instruction *lexer(const char *program, int len) {
    enum instruction *out = malloc(len + 1);

    for(int i = 0; i < len; i++) {
        switch(program[i]) {
        case '>':
            out[i] = POINTER_INCREMENT;
            break;
        case '<':
            out[i] = POINTER_DECREMENT;
            break;
        case '+':
            out[i] = CELL_INCREMENT;
            break;
        case '-':
            out[i] = CELL_DECREMENT;
            break;
        case '.':
            out[i] = CELL_OUTPUT;
            break;
        case ',':
            out[i] = CELL_INPUT;
            break;
        case '[':
            out[i] = JUMP_OPEN;
            break;
        case ']':
            out[i] = JUMP_CLOSE;
            break;
        default:
            out[i] = SKIP;
            break;
        }
    }

    return out;
}

/* Compiling + Assembling */

int assign_label_name() {
    if(label_next >= LABEL_STACK_SIZE) {
        puts("Label stack overflow");
        return -1;
    }

    label_stack[++label_stack_pointer] = label_next++;
    return label_stack[label_stack_pointer];
}

int free_label_name() {
    if(label_next <= 0) {
        puts("Label stack underflow");
        return -1;
    }

    return label_stack[label_stack_pointer--];
}

void compile_instruction(enum instruction inst, FILE *f) {
    switch(inst) {
    case SKIP:
        break;
    case PROGRAM_START:
        fprintf(f, HEADER_ASM);
        fprintf(f, STACK_INIT_ASM);
        break;
    case POINTER_INCREMENT:
        fprintf(f, POINTER_INCREMENT_ASM);
        break;
    case POINTER_DECREMENT:
        fprintf(f, POINTER_DECREMENT_ASM);
        break;
    case CELL_INCREMENT:
        fprintf(f, CELL_INCREMENT_ASM);
        break;
    case CELL_DECREMENT:
        fprintf(f, CELL_DECREMENT_ASM);
        break;
    case CELL_OUTPUT:
        fprintf(f, CELL_OUTPUT_ASM);
        break;
    case CELL_INPUT:
        fprintf(f, CELL_INPUT_ASM);
        break;
    case JUMP_OPEN:
        fprintf(f, JUMP_OPEN_ASM, assign_label_name());
        break;
    case JUMP_CLOSE:
        fprintf(f, JUMP_CLOSE_ASM, free_label_name());
        break;
    case PROGRAM_END:
        fprintf(f, STACK_CLEAN_ASM);
        fprintf(f, EXIT_ASM);
        break;
    }
}

void compile(const char *source, FILE *fasm) {
    compile_instruction(PROGRAM_START, fasm);

    int len = get_program_length(source);
    enum instruction *program = lexer(source, len);
    for(int i = 0; i < len; i++)
        compile_instruction(program[i], fasm);
    free(program);

    compile_instruction(PROGRAM_END, fasm);
}

/* Entry */
int main(int argc, char *argv[]) {
    if(argc < 2) {
        puts("Too few arguments");
        return EXIT_FAILURE;
    }

    FILE *fsource;
    fsource = fopen(argv[1], "r");
    fseek(fsource, 0, SEEK_END);
    int source_size = ftell(fsource);
    rewind(fsource);

    char *source = malloc(source_size);
    fread(source, source_size, 1, fsource);
    fclose(fsource);

    FILE *fasm;
    fasm = fopen("a.s", "w");
    if(!fasm) {
        puts("Failed to create file");
        return EXIT_FAILURE;
    }

    compile(source, fasm);

    fclose(fasm);
    free(source);
    return EXIT_SUCCESS;
}
