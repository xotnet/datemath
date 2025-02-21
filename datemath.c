#include <stdint.h>
#include <stdlib.h>

void parseDate(char* str, uint8_t* day, uint8_t* month, uint16_t* year);

/*
format "03.12.2019" or "8.2.1998"
-1 - date1 is less than date2
 0 - date1 is equal to date2
 1 - date1 is greater than date2
*/
int8_t datemath(char* date1, char* date2) {
	uint8_t lday, lmonth;
	uint16_t lyear;
	parseDate(date1, &lday, &lmonth, &lyear);
	uint8_t cday, cmonth;
	uint16_t cyear;
	parseDate(date2, &cday, &cmonth, &cyear);
	if (cyear > lyear || (cyear == lyear && cmonth > lmonth) || (cyear == lyear && cmonth == lmonth && cday > lday)) {
		return -1;
	} else if (cyear < lyear || (cyear == lyear && cmonth < lmonth) || (cyear == lyear && cmonth == lmonth && cday < lday)) {
		return 1;
	} else {
		return 0;
	}
}

void parseDate(char* str, uint8_t* day, uint8_t* month, uint16_t* year) {
    char day_s[3];
    uint16_t i = 0;
    for (;*(str+i) != '.'; i++) {
        day_s[i] = str[i];
    }
    day_s[i] = 0;
    i++;
    uint8_t p = 0;
    char month_s[3];
    for (;*(str+i) != '.'; i++) {
        month_s[p] = str[i];
        p++;
    }
    month_s[p] = 0;
    i++;
    p = 0;
    char year_s[5];
    for (;p<4; i++) {
        year_s[p] = str[i];
        p++;
    }
    year_s[p] = 0;
    *day = atoi(day_s);
    *month = atoi(month_s);
    *year = atoi(year_s);
}
