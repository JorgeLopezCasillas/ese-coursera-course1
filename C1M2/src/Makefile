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

#------------------------------------------------------------------------------
# @author: Jorge Lopez
# @date : 26 December, 2020
#
# makefile to genrate preprocessor, assembly, object, dependency, map and
# excutable output files for two different platforms.Platforms are host machine
# and msp432.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#           PLATFORM = HOST   - compile for host machine using gcc.
#           PLATFORM = MSP432 - compile for msp432 using arm-none-eabi-gcc.
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#Common Variables
COMMON_FLAGS = -Wall -Werror -g -O0 -std=c99
TARGET = c1m2


ifeq ($(PLATFORM),HOST)
# Compiler Flags and Defines
  CC = gcc
  CFLAGS = $(COMMON_FLAGS)
  CPPFLAGS = -DHOST $(INCLUDES)
  LDFLAGS = -Wl,-Map=$(TARGET).map	
  
  SIZE = size 

endif

ifeq ($(PLATFORM),MSP432)

  # Architectures Specific Flags
  LINKER_FILE = -T msp432p401r.lds
  LINKER_FILE_PATH = -L ../
  CPU =cortex-m4 
  ARCH =armv7e-m
  SPECS =nosys.specs
  OTHER_ARCH_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
  
# Compiler Flags and Defines MSP432
  SOURCES = main.c \
	  memory.c \
	  interrupts_msp432p401r_gcc.c \
	  startup_msp432p401r_gcc.c \
	  system_msp432p401r.c
  CC = arm-none-eabi-gcc
  CPPFLAGS = -DMSP432 $(INCLUDES)
  CFLAGS = $(CO_CFLAGS) $(OTHER_ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) 
  LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE_PATH) $(LINKER_FILE)

  SIZE = arm-none-eabi-size 

	
endif


#making variables for .o files , .d files, .asm files , .i files

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)


#Generate the preprocessed output of all c-program implementation files (use the –E flag).
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@
#Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

#Compile all object files
.PHONY: compile-all
compile-all: $(OBJS)

#Compile all object files and link into a final executable.
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

#This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map


