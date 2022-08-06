PROGRAM = hello.D11C.blink
PROGRAMMER = cmsis-dap
CHIPDEF = __SAMD11C14A__
CHIPNAME = at91samd11c14a
CHIPTARGET = at91samdXX
CHIPTYPE = samd11
ASF = $(HOME)/repos/asf/
LINKER = $(ASF)/sam0/utils/linker_scripts/samd11/gcc/samd11c14a_flash.ld
STARTUP = $(ASF)/sam0/utils/cmsis/samd11/source/gcc/startup_samd11
BOOTLOADER = sam_ba_Generic_D11C14A_SAMD11C14A.bin
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
AR = arm-none-eabi-ar
AS = arm-none-eabi-as
CP = arm-none-eabi-objcopy
INCLUDES = sam0/utils/cmsis/samd11/include \
	thirdparty/CMSIS/Include
OBJS = $(STARTUP).o $(PROGRAM).o
LDFLAGS += -T$(LINKER) -mthumb -mcpu=cortex-m0 -Wl,--gc-sections
CFLAGS += -mcpu=cortex-m0 -mthumb -g
CFLAGS += $(INCLUDES:%=-I $(ASF)/%) -I .
CFLAGS += -D$(CHIPDEF) -Wall
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d
$(PROGRAM).elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
$(PROGRAM).bin: $(PROGRAM).elf
	$(CP) -O binary $(PROGRAM).elf $(PROGRAM).bin
edbg: $(PROGRAM).bin
	edbg -b -t $(CHIPTYPE) -pv -f $(PROGRAM).bin
openocd:	$(PROGRAM).elf
	openocd -c "interface $(PROGRAMMER)" -c "set CHIPNAME $(CHIPNAME)" -c "source [find target/$(CHIPTARGET).cfg]" -c "program $(PROGRAM).elf verify reset exit"
bootloader:
	edbg -b -t $(CHIPTYPE) -pv -f $(BOOTLOADER)
gdb:  $(ELF)
	gdb-multiarch -ex "target extended-remote localhost:3333" $(ELF)
