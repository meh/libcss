NAME    = libcss
VERSION = 0.0.1

LIB_NAME = "${NAME}-${VERSION}.so"

INST_LIBDIR     = /usr/lib
INST_HEADERSDIR = /usr/include/

DIR     = src
FILES   = 
HEADERS = 

CC         = gcc
CXX		   = g++
CFLAGS     = -D___VERSION___="\"${VERSION}\""
LDFLAGS    = 

ifdef DEBUG
CFLAGS += -g3 -DWORKING -Wall
endif

ifdef DDEBUG
CFLAGS += -DDEBUG -g3 -Wall
endif

all: libcss

libcss: $(FILES)
	${CC} ${LDFLAGS} -dynamiclib -shared -o ${LIB_NAME} ${FILES} -lc

$(FILES): $(FILES:.o=.c)
	${CC} ${CFLAGS} -fPIC -c $*.c -o $*.lo

install: all
	mkdir -p ${INST_LIBDIR}
	mkdir -p ${INST_HEADERSDIR}
###
	chmod a+rx ${INST_LIBDIR}/${LIB_NAME}
	chmod a+r ${INST_HEADERSDIR}/css.h

uninstall:
	rm -f ${INST_LIBDIR}/${LIB_NAME}
	rm -f ${INST_HEADERSDIR}/css.h
	
clean:
	rm -f ${LIB_NAME}
	find src | egrep "\.l?o" | xargs rm -f

