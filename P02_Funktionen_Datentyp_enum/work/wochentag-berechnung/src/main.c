#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {
    JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
} month_t;

typedef struct {
    int year;
    int month;
    int day;
} date_t;

typedef enum {
    Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat
} weekday_t;

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
int is_leap_year(int year) {
    int returnVal;
    returnVal = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                returnVal = 1;
            } else {
                returnVal = 0;
            }
        } else {
            returnVal = 1;
        }
    }
    return returnVal;
}

/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
int get_month_length(int year, int month) {
    int returnVal;
    if (month == FEB) {
        if (is_leap_year(year)) {
            returnVal = 29;
        } else {
            returnVal = 28;
        }
    } else if (month % 2 == 1 && month <= 7) {
        returnVal = 31;
    } else if (month % 2 == 0 && month > 7) {
        returnVal = 31;
    } else {
        returnVal = 30;
    }
    return returnVal;
}

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
int is_gregorian_date(int year, int month, int day) {
    int returnVal;
    if (year >= 1583 && year < 10000) {
        returnVal = 1;
    } else if (year == 1582) {
        if (month >= 11) {
            returnVal = 1;
        } else if (month == 10 && day > 14) {
            returnVal = 1;
        } else {
            returnVal = 0;
        }
    } else {
        returnVal = 0;
    }
    return returnVal;
}

/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
int is_date_valid(int year, int month, int day) {
    int returnVal;
    returnVal = 0;
    if (is_gregorian_date(year, month, day) == 1) {
        if (month >= 1 && month <= 12) {
            if (day >= 1 && day <= get_month_length(year, month)) {
                returnVal = 1;
            }
        }
    }
    return returnVal;
}

/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
weekday_t get_weekday(date_t date) {
    // assert(is_date_valid(date.year, date.month, date.day));
    if (is_date_valid(date.year, date.month, date.day) == 0) {
        printf("Date is not valid\n");
        return EXIT_FAILURE;
    }

    return (date.year + date.year / 4 - date.year / 100 + date.year / 400 + (13 * date.month + 8) / 5 + date.day) % 7;
}

/**
 * @brief   TASK2: print weekday as 3-letter abbreviated English day name
 */
char *parse_weekday(int weekday) {
    char *weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return weekdays[weekday];
}

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Error! Expected 1 argument but got %d \n", argc - 1);
        return EXIT_FAILURE;
    }
    date_t datum;
    sscanf(argv[1], "%d-%d-%d", &datum.year, &datum.month, &datum.day);
    if (is_date_valid(datum.year, datum.month, datum.day) == 0) {
        printf("Date is not valid\n");
        return EXIT_FAILURE;
    }
    char weekday = get_weekday(datum);
    printf("%04d-%02d-%02d is a %s\n", datum.year, datum.month, datum.day, parse_weekday(weekday));

    return EXIT_SUCCESS;
}
