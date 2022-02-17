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
#ifndef READ_H
#define READ_H

/// I/O error which leads to aborting.
#define READ_ERROR (-2)

/**
 * @brief     Reads a line from stdin and tries to parse it as number (with optional leading and trailing spaces).
 * @param[in] maxResult  gives the limit for the number to be read.
 * @returns   the succesfully read and parsed number or a negative value if in error (READ_ERROR in case of I/O error).
 */
int getInt(int maxResult);

#endif
