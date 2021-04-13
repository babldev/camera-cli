ifeq ($(shell uname -m), arm64)
	CCFLAGS = -L /opt/homebrew/lib -I /opt/homebrew/include
else
	CCFLAGS = -L /usr/local/lib
endif

main: main.c
	gcc $(CCFLAGS) -luvc -o camera-cli main.c
