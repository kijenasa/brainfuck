CC=gcc
DESTDIR=/usr/local/bin
BINNAME=brainfuck

all: build

build: main.c
	${CC} -o brainfuck main.c

clean: 
	rm brainfuck

install: all
	mkdir -p ${DESTDIR}
	cp -f ${BINNAME} ${DESTDIR}
	chmod 755 ${DESTDIR}/${BINNAME}
