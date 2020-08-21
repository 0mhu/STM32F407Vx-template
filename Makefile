################################Shimatta Makefile####################################
#CPU:		STM32F407VET6
#Compiler:	arm-none-eabi
#####################################################################################
#Add Files and Folders below#########################################################
CFILES 	= main.c startup/startup_stm32f407vx.c setup/system_stm32f4xx.c
ASFILES =
INCLUDEPATH = -Iinclude -Imathlib/include

OBJDIR_BASE = obj
TARGET_BASE = stm32f407-template
LIBRARYPATH = -L. -Lstartup -Lmathlib
LIBRARIES = 

DEFINES = -DSTM32F407xx -DSTM32F4XX -DARM_MATH_CM4 -DHSE_VALUE=8000000UL
MAPFILE_BASE = memory-mapping
LINKER_SCRIPT=stm32f407ve.ld 

export GIT_VER = $(shell git describe --always --dirty --tags)
DEFINES += -DGIT_VER=$(GIT_VER)

ifneq ($(VERBOSE),true)
QUIET=@
else
QUIET=
endif


DEBUG_DEFINES =
RELEASE_DEFINES =

###################################################################################
ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE=arm-none-eabi-
endif

CC=$(CROSS_COMPILE)gcc
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump
SIZE=$(CROSS_COMPILE)size

CFLAGS_RELEASE = -O3 -g
CFLAGS_DEBUG = -O0 -g

LFLAGS_RELEASE = -Wl,--gc-sections
LFLAGS_DEBUG =

CFLAGS =
LFLAGS =

ifneq ($(DEBUGBUILD),true)
DEFINES += $(RELEASE_DEFINES)
CFLAGS += $(CFLAGS_RELEASE)
LFLAGS += $(LFLAGS_RELEASE)
target = $(TARGET_BASE)-release
OBJDIR = $(OBJDIR_BASE)/release
MAPFILE = $(MAPFILE_BASE)-release
else
DEFINES += $(DEBUG_DEFINES)
target = $(TARGET_BASE)-debug
CFLAGS += $(CFLAGS_DEBUG)
LFLAGS += $(LFLAGS_DEBUG)
OBJDIR = $(OBJDIR_BASE)/debug
MAPFILE = $(MAPFILE_BASE)-debug
endif

LFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
LFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 --disable-newlib-supplied-syscalls -nostartfiles
LFLAGS += -T$(LINKER_SCRIPT) -Wl,-Map=$(MAPFILE).map -Wl,--print-memory-usage

CFLAGS += -c -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostartfiles
CFLAGS += -Wall -Wextra -Wold-style-declaration -Wuninitialized -Wmaybe-uninitialized -Wunused-parameter -Wimplicit-fallthrough=3 -Wsign-compare

####################################################################################

OBJ = $(CFILES:%.c=$(OBJDIR)/%.c.o)
ASOBJ += $(ASFILES:%.S=$(OBJDIR)/%.S.o)

default: $(target).elf

all: debug release

release:
	$(QUIET)$(MAKE) DEBUGBUILD=false

debug:
	$(QUIET)$(MAKE) DEBUGBUILD=true

%.bin: %.elf
	$(QUIET)$(OBJCOPY) -O binary $^ $@
%.hex: %.elf
	$(QUIET)$(OBJCOPY) -O ihex $^ $@

#Linking
$(target).elf: $(OBJ) $(ASOBJ) $(LINKER_SCRIPT)
	@echo [LD] $@
	$(QUIET)$(CC) $(LFLAGS) $(LIBRARYPATH) -o $@ $(OBJ) $(ASOBJ) $(LIBRARIES)
	$(QUIET)$(SIZE) $@
	@echo "Built Version $(GIT_VER)"

#Compiling
$(OBJ):
	@echo [CC] $@
	$(eval OUTPATH=$(dir $@))
	@mkdir -p $(OUTPATH)
	$(QUIET)$(CC) $(CFLAGS) -MMD -MT $@ $(INCLUDEPATH) $(DEFINES) -o $@ $(@:$(OBJDIR)/%.c.o=%.c)
$(ASOBJ):
	@echo [AS] $@
	$(eval OUTPATH=$(dir $@))
	@mkdir -p $(OUTPATH)
	$(QUIET)$(CC) $(CFLAGS) -MMD -MT $@ $(INCLUDEPATH) $(DEFINES) -o $@ $(@:$(OBJDIR)/%.S.o=%.S)


.PHONY: qtproject-legacy qtproject qtproject-debug clean mrproper objcopy disassemble program program-debug

program-debug:
	$(QUIET)$(MAKE) DEBUGBUILD=true program

program: $(target).elf
	./program-device.sh $<

disassemble: $(target).elf
	$(QUIET)$(OBJDUMP) -D -s $< > $(target).lss

objcopy: $(target).bin $(target).hex

mrproper: clean
	@echo "Purging project files..."
	$(QUIET)rm -f $(target).pro $(target).creator $(target).files $(target).cflags $(target).cxxflags $(target).includes $(target).config

clean:
	@echo -n "Cleaning up derived files for "
ifneq ($(DEBUGBUILD),true)
	@echo "RELEASE build"
else
	@echo "DEBUG build"
endif
	$(QUIET)rm -f $(target).elf $(target).bin $(target).hex $(OBJ) $(ASOBJ) $(mapfile).map $(CFILES:%.c=$(OBJDIR)/%.c.d) $(ASFILES:%.S=$(OBJDIR)/%.S.d) 
	$(QUIET)rm -rf $(OBJDIR)/*
ifneq ($(DEBUGBUILD),true)
	$(QUIET)$(MAKE) DEBUGBUILD=true clean
endif

qtproject-legacy:
	echo -e "TEMPLATE = app\nCONFIG -= console app_bundle qt" > $(target).pro
	echo -e "SOURCES += $(CFILES) $(ASFILES)" >> $(target).pro
	echo -ne "INCLUDEPATH += " >> $(target).pro
	echo "$(INCLUDEPATH)" | sed "s!-I!./!g" >> $(target).pro
	echo -ne "HEADERS += " >> $(target).pro
	find -name "*.h" | tr "\\n" " " >> $(target).pro
	echo -ne "\nDEFINES += " >> $(target).pro
	echo "$(DEFINES)" | sed "s/-D//g" >> $(target).pro

qtproject-debug:
	@echo "Generating debug build project"
	$(QUIET)$(MAKE) DEBUGBUILD=true qtproject

qtproject:
	$(QUIET)rm -f $(target).files $(target).cflags $(target).config $(target).creator $(target).includes $(target).creator.user
	@echo "Generating source file list"
	$(QUIET)echo "$(CFILES)" | tr ' ' '\n' > $(target).files
	@echo -n "Appending found header files from folders "
	@echo `echo $(INCLUDEPATH) | sed "s/-I//g"`
	$(QUIET)for dir in `echo $(INCLUDEPATH) | sed "s/-I//g"`; do \
		find `echo "$${dir}"` -name "*.h" >> $(target).files; \
	done
	@echo "Generating $(target).cflags"
	$(QUIET)echo "" > $(target).cflags
	@echo "Generating $(target).includes"
	$(QUIET)echo $(INCLUDEPATH) | sed "s/-I/,/g" | tr , '\n' | sed "/^$$/d" > $(target).includes;
	@echo "Generating $(target).config"
	$(QUIET)echo $(DEFINES) | sed "s/-D/,#define /g" | tr , '\n' | sed "/^$$/d" > $(target).config
	@echo "Generating $(target).creator"
	$(QUIET)echo "[GENERAL]" > $(target).creator

-include $(CFILES:%.c=$(OBJDIR)/%.c.d) $(ASFILES:%.S=$(OBJDIR)/%.S.d)
