all: static dynamic libfunctions

static: libfunctions
	gcc -o static static.c -L./ -l realization1 -Wl,-rpath=./

dynamic: libfunctions
	gcc -rdynamic -o dynamic dynamic.c -ldl

libfunctions: functions
	gcc -shared -o librealization1.so librealization1.o -lm
	gcc -shared -o librealization2.so librealization2.o -lm

functions: functions.h librealization1.c librealization2.c
	gcc -fPIC -c librealization1.c
	gcc -fPIC -c librealization2.c

clean:
	rm -f *.so *.o static dynamic