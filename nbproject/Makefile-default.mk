#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU/7_Segment/_7_SEGMENT.c ECU/Button/BUTTON.c ECU/DC_Motor/DC_MOTOR.c ECU/Keypad/KEYPAD.c ECU/LED/LED.c ECU/Relay/RELAY.c ECU/ECU_INIT.c MCAL/ADC/ADC.c MCAL/EEPROM/EEPROM.c MCAL/GPIO/GPIO.c MCAL/Interrupt/INT_CONFIG.c MCAL/Interrupt/INT_EXTERNAL.c MCAL/Interrupt/INT_INTERNAL.c MCAL/Interrupt/INT_MANAGER.c app.c MCAL/DEVICE_CFG.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 ${OBJECTDIR}/ECU/Button/BUTTON.p1 ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 ${OBJECTDIR}/ECU/LED/LED.p1 ${OBJECTDIR}/ECU/Relay/RELAY.p1 ${OBJECTDIR}/ECU/ECU_INIT.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/MCAL/DEVICE_CFG.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d ${OBJECTDIR}/ECU/Button/BUTTON.p1.d ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d ${OBJECTDIR}/ECU/LED/LED.p1.d ${OBJECTDIR}/ECU/Relay/RELAY.p1.d ${OBJECTDIR}/ECU/ECU_INIT.p1.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d ${OBJECTDIR}/app.p1.d ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 ${OBJECTDIR}/ECU/Button/BUTTON.p1 ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 ${OBJECTDIR}/ECU/LED/LED.p1 ${OBJECTDIR}/ECU/Relay/RELAY.p1 ${OBJECTDIR}/ECU/ECU_INIT.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/MCAL/DEVICE_CFG.p1

# Source Files
SOURCEFILES=ECU/7_Segment/_7_SEGMENT.c ECU/Button/BUTTON.c ECU/DC_Motor/DC_MOTOR.c ECU/Keypad/KEYPAD.c ECU/LED/LED.c ECU/Relay/RELAY.c ECU/ECU_INIT.c MCAL/ADC/ADC.c MCAL/EEPROM/EEPROM.c MCAL/GPIO/GPIO.c MCAL/Interrupt/INT_CONFIG.c MCAL/Interrupt/INT_EXTERNAL.c MCAL/Interrupt/INT_INTERNAL.c MCAL/Interrupt/INT_MANAGER.c app.c MCAL/DEVICE_CFG.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1: ECU/7_Segment/_7_SEGMENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_Segment" 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 ECU/7_Segment/_7_SEGMENT.c 
	@-${MV} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.d ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Button/BUTTON.p1: ECU/Button/BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Button" 
	@${RM} ${OBJECTDIR}/ECU/Button/BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Button/BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Button/BUTTON.p1 ECU/Button/BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU/Button/BUTTON.d ${OBJECTDIR}/ECU/Button/BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Button/BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1: ECU/DC_Motor/DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 ECU/DC_Motor/DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.d ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Keypad/KEYPAD.p1: ECU/Keypad/KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Keypad" 
	@${RM} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 ECU/Keypad/KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU/Keypad/KEYPAD.d ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/LED.p1: ECU/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/LED.p1 ECU/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/LED.d ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Relay/RELAY.p1: ECU/Relay/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Relay" 
	@${RM} ${OBJECTDIR}/ECU/Relay/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Relay/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Relay/RELAY.p1 ECU/Relay/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU/Relay/RELAY.d ${OBJECTDIR}/ECU/Relay/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Relay/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ECU_INIT.p1: ECU/ECU_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ECU_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ECU_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ECU_INIT.p1 ECU/ECU_INIT.c 
	@-${MV} ${OBJECTDIR}/ECU/ECU_INIT.d ${OBJECTDIR}/ECU/ECU_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ECU_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO.p1: MCAL/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 MCAL/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1: MCAL/Interrupt/INT_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 MCAL/Interrupt/INT_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.d ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1: MCAL/Interrupt/INT_EXTERNAL.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 MCAL/Interrupt/INT_EXTERNAL.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.d ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1: MCAL/Interrupt/INT_INTERNAL.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 MCAL/Interrupt/INT_INTERNAL.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.d ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1: MCAL/Interrupt/INT_MANAGER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 MCAL/Interrupt/INT_MANAGER.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.d ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DEVICE_CFG.p1: MCAL/DEVICE_CFG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DEVICE_CFG.p1 MCAL/DEVICE_CFG.c 
	@-${MV} ${OBJECTDIR}/MCAL/DEVICE_CFG.d ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1: ECU/7_Segment/_7_SEGMENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_Segment" 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1 ECU/7_Segment/_7_SEGMENT.c 
	@-${MV} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.d ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_Segment/_7_SEGMENT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Button/BUTTON.p1: ECU/Button/BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Button" 
	@${RM} ${OBJECTDIR}/ECU/Button/BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Button/BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Button/BUTTON.p1 ECU/Button/BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU/Button/BUTTON.d ${OBJECTDIR}/ECU/Button/BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Button/BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1: ECU/DC_Motor/DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1 ECU/DC_Motor/DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.d ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_Motor/DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Keypad/KEYPAD.p1: ECU/Keypad/KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Keypad" 
	@${RM} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1 ECU/Keypad/KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU/Keypad/KEYPAD.d ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Keypad/KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/LED.p1: ECU/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/LED.p1 ECU/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/LED.d ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Relay/RELAY.p1: ECU/Relay/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Relay" 
	@${RM} ${OBJECTDIR}/ECU/Relay/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Relay/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Relay/RELAY.p1 ECU/Relay/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU/Relay/RELAY.d ${OBJECTDIR}/ECU/Relay/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Relay/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ECU_INIT.p1: ECU/ECU_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ECU_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ECU_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ECU_INIT.p1 ECU/ECU_INIT.c 
	@-${MV} ${OBJECTDIR}/ECU/ECU_INIT.d ${OBJECTDIR}/ECU/ECU_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ECU_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO.p1: MCAL/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 MCAL/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1: MCAL/Interrupt/INT_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1 MCAL/Interrupt/INT_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.d ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1: MCAL/Interrupt/INT_EXTERNAL.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1 MCAL/Interrupt/INT_EXTERNAL.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.d ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_EXTERNAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1: MCAL/Interrupt/INT_INTERNAL.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1 MCAL/Interrupt/INT_INTERNAL.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.d ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_INTERNAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1: MCAL/Interrupt/INT_MANAGER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1 MCAL/Interrupt/INT_MANAGER.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.d ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupt/INT_MANAGER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DEVICE_CFG.p1: MCAL/DEVICE_CFG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DEVICE_CFG.p1 MCAL/DEVICE_CFG.c 
	@-${MV} ${OBJECTDIR}/MCAL/DEVICE_CFG.d ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DEVICE_CFG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MC.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MC.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/MC.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/MC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MC.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MC.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
