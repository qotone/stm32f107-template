# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (rtthread)

# -DCMAKE_EXPORT_COMPILE_COMMANDS=1
# output compile_json.txt
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


# set(CROSS_PATH /home/luoyang/App/GCC4Embed/hisi-linux/x86-arm/arm-hisiv600-linux)

set(CROSS arm-linux-gnueabihf-)
# Target operating system name.
#set(CMAKE_SYSTEM_NAME Linux)


set(CROSS_PATH /opt/gcc-arm-none-eabi-6_2-2016q4)

# Target operating system name.
#set(CMAKE_SYSTEM_NAME Linux)

# Name of C compiler.
set(CMAKE_C_COMPILER "${CROSS_PATH}/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "${CROSS_PATH}/bin/arm-none-eabi-g++")

# Where to look for the target environment. (More paths can be added here)
set(CMAKE_FIND_ROOT_PATH "${CROSS_PATH}")

# Adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment only.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Search headers and libraries in the target environment only.
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


# Name of C compiler.
set(CMAKE_C_COMPILER "${CROSS}gcc")
set(CMAKE_CXX_COMPILER "${CROSS}g++")

# c flags -fno-aggressive-loop-optimizations
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLINUX -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=neon -mno-unaligned-access -ffunction-sections" CACHE STRING "Set C Compiler Flags" FORCE)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLINUX -D_ARCH=arm -DSTM32F10X_CL -D_DEVTOOLS=gnu -O -Wall" CACHE STRING "Set C Compiler Flags" FORCE)



# link flags
# set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=neon -mno-unaligned-access -fno-aggressive-loop-optimizations"  CACHE STRING "Set link Flags" FORCE)

# mmp libs
# set(MPP_PATH /media/luoyang/Workspace/Hi3531DV100_SDK_V2.0.4.0/mpp)

# rtthread libs
set(RTT_ROOT /mnt/f/GD32/rt-thread-3.1.4)
# set(RTT_ROOT /media/luoyang/Workspace/GD32/rt-thread-3.1.4)

# Create a sources variable with link to all c files to compile
set(SOURCES
  ${PROJECT_SOURCE_DIR}/Libraries/CMSIS/GD/GD32F10x/Source/system_gd32f10x.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_adc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_bkp.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_can.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_crc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_dbg.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_dma.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_enet.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_exmc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_exti.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_fmc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_fwdgt.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_gpio.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_i2c.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_misc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_pmu.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_rcu.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_rtc.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_sdio.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_spi.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_timer.c
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Source/gd32f10x_usart.c
  )

aux_source_directory(${PROJECT_SOURCE_DIR}/applications APP_SOURCES)

# Include header files
# include_directories(
#     ${PROJECT_SOURCE_DIR}/app/src/
#     ${PROJECT_SOURCE_DIR}/app/src/common
#     ${PROJECT_SOURCE_DIR}/app/src/matrix
#     ${PROJECT_SOURCE_DIR}/app/src/cameraCtrl
#     ${PROJECT_SOURCE_DIR}/app/src/record
#     /home/luoyang/nfsroot/imx6/include
#     /home/luoyang/Dev/cross/imx6/nanomsg/include
#     ${PROJECT_SOURCE_DIR}/target/include
#     ${PROJECT_SOURCE_DIR}/app/src/common
#     ${PROJECT_SOURCE_DIR}/app/src/matrix
#     ${PROJECT_SOURCE_DIR}/app/src/cameraCtrl
#     ${PROJECT_SOURCE_DIR}/app/src/record
#     /home/luoyang/nfsroot/imx6/include
#     /home/luoyang/Dev/cross/imx6/nanomsg/include
#     /home/luoyang/Dev/cross/hi3531d_v600/goahead_v218/include

# )

# link libs path
# link_directories(
#     ${PROJECT_SOURCE_DIR}/target/lib
#     /home/luoyang/nfsroot/imx6/lib
#     /home/luoyang/Dev/cross/imx6/nanomsg/lib
# )


# Add an executable
add_executable(${PROJECT_NAME} ${SOURCES} ${APP_SOURCES})

# Set the directories that should be included in the build command for this target
# when running gcc these will be included as -I/directories/path/
target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/applications
  ${PROJECT_SOURCE_DIR}/Libraries/GD32F10x_standard_peripheral/Include  
  ${PROJECT_SOURCE_DIR}/Libraries/CMSIS
  ${PROJECT_SOURCE_DIR}/Libraries/CMSIS/GD/GD32F10x/Include
  ${PROJECT_SOURCE_DIR}/board
  ${RTT_ROOT}/include  
)


# Link libs
# target_link_libraries( ${PROJECT_NAME}
#                        PRIVATE
#                        pthread
#                        osa
#                        mb
#                        mxml
#                        sqlite3
#                        nanomsg
#                        nsl
# )
