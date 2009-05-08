NAME    = libcss
VERSION = 0.0.1

LIB_NAME = ${NAME}-${VERSION}.so

INST_LIBDIR     = /usr/lib
INST_HEADERSDIR = /usr/include/

DIR     = src
INCL	= include
FILES   = ${DIR}/Document.o ${DIR}/Node.o ${DIR}/NodeList.o ${DIR}/Property.o ${DIR}/PropertyList.o ${DIR}/Exception.o ${DIR}/ExceptionList.o
HEADERS = ${INCL}/api.h ${INCL}/Document.h ${INCL}/Node.h ${INCL}/NodeList.h ${INCL}/Property.h ${INCL}/PropertyList.h ${INCL}/Exception.h ${INCL}/ExceptionList.h

CC         = gcc
CXX		   = g++
CFLAGS     = -D___VERSION___="\"${VERSION}\"" -I./include/
LDFLAGS    = 

ifdef DEBUG
CFLAGS += -g3 -DWORKING -Wall
endif

ifdef DDEBUG
CFLAGS += -DDEBUG -g3 -Wall
endif

ifdef SELECTOR
CFLAGS  += $(shell xml2-config --cflags)
LDFLAGS += $(shell xml2-config --libs)
FILES   += ${DIR}/Selector.o ${DIR}/SimpleSelector.o
HEADERS += ${INCL}/Selector.h ${INCL}/SimpleSelector.h
xml_cflags  = $(shell xml2-config --cflags)
xml_ldflags = $(shell xml2-config --libs)
$(shell cp  bin/css-config.mk bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_CFLAGS%#${xml_cflags}#'   bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_LDFLAGS%#${xml_ldflags}#' bin/.css-config)
else
$(shell cp  bin/css-config.mk bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_CFLAGS%##'  bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_LDFLAGS%##' bin/.css-config)
endif

all: libcss

libcss: $(FILES)
	${CC} ${LDFLAGS} -dynamiclib -shared -o ${LIB_NAME} ${FILES} -lc

$(FILES): $(FILES:.o=.c)
	${CC} ${CFLAGS} -fPIC -c $*.c -o $*.o

install: all
	mkdir -p         ${INST_LIBDIR}
	mkdir -p         ${INST_HEADERSDIR}
	install          ${HEADERS} ${INST_HEADERSDIR}/
	mv               bin/.css-config /usr/bin/css-config
	chmod     a+rx   ${INST_LIBDIR}/${LIB_NAME}
	chmod -R  a+r    ${INST_HEADERSDIR}/

uninstall:
	rm -f ${INST_LIBDIR}/${LIB_NAME}
	rm -f ${INST_HEADERSDIR}/css.h
	
clean:
	rm -f ${LIB_NAME}
	find src | egrep "\.l?o" | xargs rm -f

