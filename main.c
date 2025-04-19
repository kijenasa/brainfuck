#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "asm.h"
#include "config.h"

enum instruction {
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

/* Lexer */
enum instruction *lexer(const char *program, int *len) {
    *len = strlen(program);
    enum instruction *out = malloc(*len + 1);

    for(int i = 0; i < *len; i++) {
        switch(program[i]) {
        case '>':
            out[i] = POINTER_INCREMENT;
            printf("POINTER_INCREMENT\n");
            break;
        case '<':
            out[i] = POINTER_DECREMENT;
            printf("POINTER_DECREMENT\n");
            break;
        case '+':
            out[i] = CELL_INCREMENT;
            printf("CELL_INCREMENT\n");
            break;
        case '-':
            out[i] = CELL_DECREMENT;
            printf("CELL_DECREMENT\n");
            break;
        case '.':
            out[i] = CELL_OUTPUT;
            printf("CELL_OUTPUT\n");
            break;
        case 'y':
            out[i] = CELL_INPUT;
            printf("CELL_INPUT\n");
            break;
        case '[':
            out[i] = JUMP_OPEN;
            printf("JUMP_OPEN\n");
            break;
        case ']':
            out[i] = JUMP_CLOSE;
            printf("JUMP_CLOSE\n");
            break;
        }
    }

    return out;
}

/* Compiling + Assembling */
void compile_instruction(enum instruction inst, FILE *f) {
    switch(inst) {
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
        fprintf(f, CELL_INCREMENT_ASM);
        break;
    case CELL_OUTPUT:
        fprintf(f, CELL_OUTPUT_ASM);
        break;
    case CELL_INPUT:
        fprintf(f, CELL_INPUT_ASM);
        break;
    case JUMP_OPEN:
        // fprintf(f, JUMP_OPEN_ASM, "label_temp");
        break;
    case JUMP_CLOSE:
        // fprintf(f, JUMP_CLOSE_ASM, "label_temp");
        break;
    case PROGRAM_END:
        fprintf(f, STACK_CLEAN_ASM);
        fprintf(f, EXIT_ASM);
        break;
    }
}

void compile(const char *source, FILE *fasm) {
    compile_instruction(PROGRAM_START, fasm);

    int len;
    enum instruction *program = lexer(source, &len);
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

    char *source = malloc(source_size + 1);
    fread(source, source_size, 1, fsource);
    fclose(fsource);

    source[source_size] = '\0';

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
