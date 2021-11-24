################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
001-MASTER.lss \

FLASH_IMAGE += \
001-MASTER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 001-MASTER.elf secondary-outputs

# Tool invocations
001-MASTER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,001-MASTER.map -mmcu=atmega32 -o "001-MASTER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

001-MASTER.lss: 001-MASTER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 001-MASTER.elf  >"001-MASTER.lss"
	@echo 'Finished building: $@'
	@echo ' '

001-MASTER.hex: 001-MASTER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 001-MASTER.elf  "001-MASTER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 001-MASTER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 001-MASTER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 001-MASTER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
