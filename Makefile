cflags = -D_FILE_OFFSET_BITS=64 -I ./include 
libs = -lpthread -lm

#Release profile

obj = release/obj/main.o release/obj/utestf.o

hdr = include/utestf.h
 
release_bin = release/utestf
CCX = gcc -o
CC = gcc -c
release_command = $(CCX) $(release_bin) $(obj) $(ldflags) $(libs)

release: $(obj) $(hdr)
	$(release_command)

release/obj/main.o: src/main.c
	$(CC) src/main.c -o release/obj/main.o $(cflags) 

release/obj/utestf.o: src/utestf.c include/utestf.h
	$(CC) src/utestf.c -o release/obj/utestf.o $(cflags) 

run: release 
ifneq ("$(wildcard $(release_bin))","")
	$(release_bin)
else
	$(release_command)
	$(release_bin)
endif

.PHONY: rebuild

rebuild: 
	$(MAKE) clean
	$(MAKE) release
	
# Debug profile

dbg = debug/obj/main.o debug/obj/utestf.o
 
debug_bin = debug/utestf
CCGX = gcc -g -DDEBUG -o
CCG = gcc -g -DDEBUG -c
debug_command = $(CCGX) $(debug_bin) $(dbg) $(ldflags) $(libs)
	
debug: $(dbg) $(hdr)
	$(debug_command)

debug/obj/main.o: src/main.c
	$(CCG) src/main.c -o debug/obj/main.o $(cflags) 

debug/obj/utestf.o: src/utestf.c include/utestf.h
	$(CCG) src/utestf.c -o debug/obj/utestf.o $(cflags) 

run_debug: debug
ifneq ("$(wildcard $(debug_bin))","")
	gdb $(debug_bin)
else
	$(debug_command)
	gdb $(debug_bin)
endif

.PHONY: rebuild_debug
	
rebuild_debug: 
	$(MAKE) clean
	$(MAKE) debug

#Others rules

.PHONY: prepare clean

prepare:
	mkdir -p debug release debug/obj release/obj
	mkdir -p src include
clean:
	rm -R -f $(obj) $(dbg) release/obj/* debug/obj/* 
	rm -R -f $(release_bin) $(debug_bin)

