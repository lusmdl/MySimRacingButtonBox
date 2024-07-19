/**
 * @file ProjectConfig.hpp
 * @brief Configuration file for project settings and definitions.
 */

#ifndef PROJECT_CONFIG_HPP
#define PROJECT_CONFIG_HPP

//#define LSMDL_DEBUGMODE

#ifdef LSMDL_DEBUGMODE
#warning "ATMEGA runs in debug mode!!! the envirement should be an arduino uno and the RX and TX pins schould be unconnected, because of the serial communication!"
#endif

#define BTN_NUMBER          16
#define BTN_MATRIX_R        4
#define BTN_MATRIX_L        4

#define BTN_MATRIX_L1       0
#define BTN_MATRIX_L2       1
#define BTN_MATRIX_L3       2
#define BTN_MATRIX_L4       3

#define BTN_MATRIX_R1       4
#define BTN_MATRIX_R2       5
#define BTN_MATRIX_R3       6
#define BTN_MATRIX_R4       7

#define I2C_ADDR            8

#endif