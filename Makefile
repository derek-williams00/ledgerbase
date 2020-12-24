# Compiler:
CC = gcc

# Compiler Flags:
#  -g     puts debug info into output
#  -Wall  enables most warnings
CFLAGS = -g -Wall

# Targets:
MAIN_TARGETS = $(wildcard programs/*.c)
## TEST_TARGETS = $(wildcard tests/*.c)




