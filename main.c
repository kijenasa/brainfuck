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
    out[0] = PROGRAM_START;
    printf("PROGRAM_START\n");

    int i;
    for(i = 1; i < *len; i++) {
        switch(program[i - 1]) {
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
    out[i] = PROGRAM_END;
    printf("PROGRAM_END\n");

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
        fprintf(f, JUMP_OPEN_ASM, "label_temp");
        break;
    case JUMP_CLOSE:
        fprintf(f, JUMP_CLOSE_ASM, "label_temp");
        break;
    case PROGRAM_END:
        fprintf(f, STACK_CLEAN_ASM);
        break;
    }
}

void assemble() {
    ASSEMBLE("a");
    LINK("a");
}

/* Entry */
int main(int argc, char *argv[]) {
    char program_name[] = "a";

    int len;
    enum instruction *program =
        lexer(">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<"
              "+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+.",
              &len);

    FILE *fasm;
    fasm = fopen("a.s", "w");
    if(!fasm) {
        puts("Failed to create file");
        return -1;
    }

    for(int i = 0; i < len; i++) {
        compile_instruction(program[i], fasm);
    }

    assemble();

    free(program);
    return EXIT_SUCCESS;
}
