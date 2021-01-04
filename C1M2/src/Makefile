#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#
#------------------------------------------------------------------------------
# @author: Jorge Lopez
# @date : 26 December, 2020
#
# makefile to genrate preprocessor, assembly, object, dependency, map and
# excutable output files for two different platforms.Platforms are host machine
# and msp432.
#
# Build Targets:
#      
# Use: <FILE>.o - builds <FILE>.o object file
#      <FILE>.i - builds <FILE>.i preprocessed output file
#      <FILE>.asm - builds <FILE>.s assembly file
#      <FILE>.dep - builds <FILE>.d dependency file
#
#      compile-all - Compile all object files, but DO NOT link
#      build - builds and links all source files
#      all - same as build
#      clean - removes all generated files
#
#
# Platform Overrides:
#           PLATFORM = HOST   - compile for host machine using gcc.
#           PLATFORM = MSP432 - compile for msp432 using arm-none-eabi-gcc.
#
#------------------------------------------------------------------------------
include sources.mk

#Common Variables
CO_CFLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
# Compiler Flags and Defines
  CC = gcc
  LD = ld
  OBJDMP = objdump
  CFLAGS = $(CO_CFLAGS)
  INCLUDES = -I ../include/common/
  CPPFLAGS = -DHOST $(INCLUDES)
  LDFLAGS = -Wl,-Map=$(TARGET).map	
  SIZE = size 

endif

ifeq ($(PLATFORM),MSP432)

# Architectures Specific Flags to MSP432
  LINKER_FILE = -T msp432p401r.lds
  LINKER_FILE_PATH = -L ../
  CPU =cortex-m4 
  ARCH =armv7e-m
  OTHER_ARCH_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
  
# Compiler Flags and Defines
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  OBJDMP = arm-none-eabi-objdump
  INCLUDES = -I ../include/common/ \
	     -I ../include/msp432/ \
	     -I ../include/CMSIS/
  CPPFLAGS = -DMSP432 $(INCLUDES)
  SPECS = nosys.specs
  CFLAGS = $(CO_CFLAGS) $(OTHER_ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) 
  LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE_PATH) $(LINKER_FILE)

  SIZE = arm-none-eabi-size 

endif

#Making variables for .o files , .d files, .asm files , .i files
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

#PATTERN RULES
#Generate the preprocessed output of all c-program implementation files (use the –E flag).
%.i : %.c
	$(CC) -E $(CPPFLAGS) $< -o $@

#Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

#Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

#Generate the dependecy files
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$ 

#Compile all object files
.PHONY: compile-all
compile-all: $(OBJS)

#Compile all object files and link into a final executable.
.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

#This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
.PHONY: clean
clean:
	rm -f *.o *.out *.map *.asm *.i *.d


