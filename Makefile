NAME    = libcss
VERSION = 0.0.1

LIB_NAME = ${NAME}.so

INST_BINDIR     = /usr/bin
INST_LIBDIR     = /usr/lib
INST_HEADERSDIR = /usr/include/css

DIR     			= src
INCL				= include
EXAM				= example
FILES  			 	= ${DIR}/Document.o ${DIR}/Node.o ${DIR}/NodeList.o ${DIR}/Property.o ${DIR}/PropertyList.o ${DIR}/Exception.o ${DIR}/ExceptionList.o
HEADERS     		= ${INCL}/api.h ${INCL}/Document.h ${INCL}/Node.h ${INCL}/NodeList.h ${INCL}/Property.h ${INCL}/PropertyList.h ${INCL}/Exception.h ${INCL}/ExceptionList.h
SELECTOR_HEADERS 	= ${INCL}/selector/api.h ${INCL}/selector/Selector.h ${INCL}/selector/SimpleSelector.h ${INCL}/selector/Attribute.h ${INCL}/selector/PseudoClass.h
EXAMPLES            = ${EXAM}/tree_expression

CC         = gcc
CXX		   = g++
CFLAGS     = -D___VERSION___="\"${VERSION}\"" -I./include/ -I./src/
LDFLAGS    = 

ifdef DEBUG
CFLAGS += -g3 -DWORKING -Wall -pedantic
endif

ifdef DDEBUG
CFLAGS += -DDEBUG -g3 -Wall
endif

ifdef SELECTOR
CFLAGS  += $(shell xml2-config --cflags)
LDFLAGS += $(shell xml2-config --libs)
FILES   += ${DIR}/selector/Selector.o ${DIR}/selector/SimpleSelector.o ${DIR}/selector/Attribute.o ${DIR}/selector/PseudoClass.o
xml_cflags  = $(shell xml2-config --cflags)
xml_ldflags = $(shell xml2-config --libs)
$(shell cp -f bin/css-config.mk bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_CFLAGS%#${xml_cflags} -DCSS_SELECTOR=1#'   bin/.css-config)
$(shell sed -r -i 's#%SELECTOR_ENABLED_LDFLAGS%#${xml_ldflags}#' bin/.css-config)
else
$(shell cp -f bin/css-config.mk bin/.css-config)
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
	mkdir -p         ${INST_HEADERSDIR}/selector
	install          ${HEADERS} ${INST_HEADERSDIR}/
	install			 ${SELECTOR_HEADERS} ${INST_HEADERSDIR}/selector/
	mv               bin/.css-config /usr/bin/css-config
	cp    			 ${LIB_NAME} ${INST_LIBDIR}/
	chmod     a+rx   ${INST_LIBDIR}/${LIB_NAME}
	chmod     a+x    ${INST_HEADERSDIR}/
	chmod     a+x    ${INST_HEADERSDIR}/selector
	chmod -R  a+r    ${INST_HEADERSDIR}/
	chmod 	  777	 ${INST_BINDIR}/css-config

uninstall:
	rm -f ${INST_LIBDIR}/${LIB_NAME}
	rm -rf ${INST_HEADERSDIR}/
	
clean:
	rm -f ${LIB_NAME}
	find src | egrep "\.l?o$$" | xargs rm -f
	find example | egrep -v "(\.c|example)$$" | xargs rm -f

examples: $(EXAMPLES)

$(EXAMPLES):
	${CC} -g3 $(shell css-config --cflags) $(shell css-config --libs) -o $@ $@.c

