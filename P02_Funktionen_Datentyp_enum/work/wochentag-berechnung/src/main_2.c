#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef enum {Sun, Mon, Tue, Wed, Thu, Fri, Sat} weekday_t;
typedef enum {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month_t;

typedef struct{
    int year, month, day;
} date_t;

int num_days_in_month(int year, month_t month);
int get_month_length(date_t date);
int is_leap_year_int(int year);
int is_leap_year(date_t date);
int is_gregorian_date(date_t date);
int is_valid_date(date_t date);
weekday_t get_weekday(date_t date);
char * parse_weekday(weekday_t weekday);


int main(int argc, const char *argv[])
{
    if(argc != 2){
		printf("Error! Excpected 1 argument but got %d \n", argc - 1);
		return EXIT_FAILURE;
	}
	
    char dtm[11];
    date_t date;
    printf("Please provide a date: \n");
    scanf("%s", dtm);
    sscanf(dtm, "%d-%d-%d", &date.year, &date.month, &date.day);
    if (!is_valid_date(date)) {
        // TODO: print helper text / info text ERROR
        fprintf(stderr,"Your date (%04d-%02d-%02d) is invalid. please make sure it's between 1582-10-15 and 9999-12-31.\n", date.year, date.month, date.day);
        return EXIT_FAILURE;
    }
    
    // assert(is_valid_date(date));
    printf("%04d-%02d-%02d is a %s\n", date.year, date.month, date.day, parse_weekday(get_weekday(date)));

    return EXIT_SUCCESS;
}

int check_int_value(int toCheck, int minInc, int maxInc) {
    return toCheck >= minInc && toCheck <= maxInc;
}

int is_valid_date(date_t date){
    if (is_gregorian_date(date)){
        return check_int_value(date.day, 1, get_month_length(date));
    }
    return 0;
}

int is_leap_year_int(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            return year % 400 == 0;
        }
        return 1;
    }
    return 0;
}

int is_leap_year(date_t date) {
    return is_leap_year_int(date.year);
}

int num_days_in_month(int year, month_t month){
    switch(month){
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;
        case FEB:
            return is_leap_year_int(year) ? 29 : 28;
        default:
            return -1;
    }
}

int get_month_length(date_t date) {
    return num_days_in_month(date.year, date.month);
}

int is_gregorian_date(date_t date) {
    int returnVal;

	if(date.year >= 1583 && date.year < 10000){
		returnVal = 1;
	} else if(date.year == 1582){
		if(date.month >= 11){
			returnVal = 1;
		} else if (date.month == 10 && date.day > 14){
			returnVal = 1;
		} else {
			returnVal = 0;
		}
	} else {
		returnVal = 0;
	}
    return returnVal;
}

char * parse_weekday(weekday_t weekday) {
    char * value[15];
    switch (weekday){
        case Sun:
            *value = "Sun";
            break;
        case Mon:
            *value = "Mon";
            break;
        case Tue:
            *value = "Tue";
            break;
        case Wed:
            *value = "Wed";
            break;
        case Thu:
            *value = "Thu";
            break;
        case Fri:
            *value = "Fri";
            break;
        case Sat:
            *value = "Sat";
            break;
        default:
            return "\0";
    }
    return *value;
}

weekday_t get_weekday(date_t date) {
    int m = 1 + (date.month + 9) % 12;
    int a = date.month < MAR ?  date.year - 1 : date.year;
    int y = a % 100;
    int c = a / 100;

    return ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
}




