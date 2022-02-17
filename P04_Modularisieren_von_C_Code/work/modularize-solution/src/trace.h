/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#ifndef TRACE_H
#define TRACE_H

#include <stdio.h>

/**
 * @brief  TRACE macro.
 * @param[in] MSG  "..." format string literal.
 * @param[in] ...  optional arguments to the format string.
 */
#define TRACE(MSG, ...) do { (void)fprintf(stderr, "TRACE: " MSG "\n", ##__VA_ARGS__); } while(0)

#endif
