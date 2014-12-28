LIBS=libfir.so

all: ${LIBS}

clean:
	rm ${LIBS}

libfir.so: fir.cpp
	g++ -fPIC -Wall -shared -Wl,-soname,$@.1 -o $@ $<
	ln -fs $@ $@.1
