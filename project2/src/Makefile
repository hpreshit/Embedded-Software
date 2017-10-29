CC = cc
CFLAGS = -std=c99 -Wall -g -O0

#ifeq ($(PLATFORM),HOST)
#CC=gcc
#CFLAGS= -Wall -Werror -g -O0 -std=c99
#SOURCES=$(HOST_SRCS_C)
#INCLUDES=$(INCLUDE_HOST) $(INCLUDE_ARM)

#else ifeq ($(PLATFORM),KL25Z) 
#CC=arm-none-eabi-gcc 
#C_FLAGS= -Wall -Werror -g -O0 -std=c99 \
#-mcpu=cortex-m0plus -march=armv6-m -mthumb \
#-mfloat-abi=soft -mfpu=fpv4-sp-d16 -specs=nosys.specs -DPROJECT1
#SOURCES=$(HOST_SRCS_C) $(KL25Z_SRCS_C) $(KL25Z_SRCS_S)
#INCLUDES=$(INCLUDE_HOST) $(INCLUDE_ARM) $(INCLUDE_KL25Z)
#LDFLAGS=-T ../platform/MKL25Z128xxx4_flash.ld

#endif


#ifeq ($(PLATFORM),KL25Z)
#HOST_SRCS_C_O=$(HOST_SRCS_C:.c=.o)
#KL25Z_SRCS_C_O=$(KL25Z_SRCS_C:.c=.o)
#KL25Z_SRCS_S_O=$(KL25Z_SRCS_S:.S=.o)
#HOST_SRCS_C_D=$(HOST_SRCS_C:.c=.d)
#KL25Z_SRCS_C_D=$(KL25Z_SRCS_C:.c=.d)
#KL25Z_SRCS_S_D=$(KL25Z_SRCS_S:.S=.d)
#OBJECTS:= $(HOST_SRCS_C_O) $(KL25Z_SRCS_C_O) $(KL25Z_SRCS_S_O)
#DEPENDANCY:= $(HOST_SRCS_C_D) $(KL25Z_SRCS_C_D) $(KL25Z_SRCS_S_D)

#else ifeq ($(PLATFORM),HOST)
#OBJECTS:= $(SOURCES:.c=.o)
#DEPENDANCY:= $(SOURCES:.c=.d)
#endif




#
# build third-party libraries
#
SUBDIRS = 3rd-party

ifdef SUBDIRS
.PHONY : $(SUBDIRS)
$(SUBDIRS) : 
	@if [ -d $@ ]; then \
		$(MAKE) --no-print-directory --directory=$@ \
			CC=$(CC) CFLAGS="$(CFLAGS)" $(MAKECMDGOALS); \
	fi	
endif


THIRD_PARTY_DIR = 3rd-party
CMOCKA_INCLUDE_DIR = $(THIRD_PARTY_DIR)/build-Debug/include
CMOCKA_LIBRARY = $(THIRD_PARTY_DIR)/build-Debug/lib/libcmocka.a

cmocka : $(SUBDIRS)

CFLAGS += -I $(CMOCKA_INCLUDE_DIR)

#
# quick and dirty build rules to demonstrate testing, not good build
# system practices.
#

#
# library
#
LIB_SRCS = \
	memory.c \
        circbuf.c \
	conversion.c \
        test_memory.c \
        test_circbuf.c \
	test_conversion.c

LIB_OBJS = $(LIB_SRCS:%.c=%.o)

LIB_HEADERS = $(LIB_SRCS:%.c=%.h)

LIB = libutils.a

#
# main executable
#
#EXE_SRCS = main.c
#EXE_OBJS = $(EXE_SRCS:%.c=%.o)

#EXE = main.out

#
# tests
MEMORY_SRCS = \
	test.c

MEMORY_OBJS = $(MEMORY_SRCS:%.c=%.o)

MEMORY_EXE = test.out


#
# Generic rule to generate objects
#
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB) : $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $^

all : $(LIB) $(EXE)

$(EXE) : $(EXE_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ -lm

test : $(MEMORY_EXE)
	./$(MEMORY_EXE)

$(MEMORY_EXE) : $(MEMORY_SRCS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(CMOCKA_LIBRARY) -lm


.PHONY : clean
clean : FORCE
	-rm -rf *~ *.o $(LIB) $(EXE) $(MEMORY_EXE) *.dSYM/

.PHONY : clobber
clobber : $(SUBDIRS) clean


FORCE :



#########################################################################



#Targets

#%.i: %.c	
#	-@echo ' '
#	-@echo 'preprocessor file .i created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $< 
	
#%.asm: %.c
#	-@echo ' '
#	-@echo 'assembly file created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<
	
#%.o: %.c
#	-@echo ' '
#	-@echo 'object file for .c file created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $< 

#%.o: %.S	
#	-@echo ' '
#	-@echo 'object file for .s file created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $< 
	
#%.d: %.c
#	-@echo ' '
#	-@echo 'dependency file for .c file.. created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -M -o $@ $<

#%.d: %.S
#	-@echo ' '
#	-@echo 'dependency file for .S file.. created: '
#	-$(CC) $(CFLAGS) $(INCLUDES) -M -o $@ $<
	

#compile-all:$(OBJECTS)


#build:$(OBJECTS) $(DEPENDANCY)
#	-@echo ' '
#	-@echo 'build in process: '
#	-$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -Xlinker -Map=project1.map $(OBJECTS) -o project1.elf
#	-@echo ' '
#	-size project1.elf
#	-@echo ' '
#	-ls -sh project1.elf

#clean:
#	-@echo ' '	
#	-@echo 'clean all the generated files: '
#	-$(RM) *.i *.asm *.o *.d *.out project1.map project1.elf
#	-@echo ' '


