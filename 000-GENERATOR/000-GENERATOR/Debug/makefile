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
000-GENERATOR.lss \

FLASH_IMAGE += \
000-GENERATOR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 000-GENERATOR.elf secondary-outputs

# Tool invocations
000-GENERATOR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,000-GENERATOR.map -mmcu=atmega32 -o "000-GENERATOR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

000-GENERATOR.lss: 000-GENERATOR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 000-GENERATOR.elf  >"000-GENERATOR.lss"
	@echo 'Finished building: $@'
	@echo ' '

000-GENERATOR.hex: 000-GENERATOR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 000-GENERATOR.elf  "000-GENERATOR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 000-GENERATOR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 000-GENERATOR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 000-GENERATOR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
