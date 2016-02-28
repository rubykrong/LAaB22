#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool isLeapYear(int year);
void dateInSecond();

int main() {
	int massMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int massLeapMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	time_t t;
	struct tm *current = NULL;
	long seconds;
	time(&t);
	int i = 0;
	int countMon = 12;
	current = localtime(&t);
	int c_day = current->tm_yday;
	int c_month = current->tm_mon;
	int c_year = current->tm_year + 1900;
	int c_hour = current->tm_hour;
	int c_minute = current->tm_min;
	int day = 0,
		month = 0,
		year = 0,
		hour = 0,
		minute = 0;
	int allDays = 0;
	printf("Birthday\n");
	scanf("%d.%d.%d %d:%d", &day, &month, &year, &hour, &minute);
	// long seconds = ((((((c_year - year) ) * leap + c_day - day) * 24 + c_hour - hour) * 60 + c_minute - minute) * 60);
	i = year;
	
	while(i <= c_year){
		if(i == c_year){
			countMon = c_month;
		} else if(i == year){
			countMon = 12 - month;
		} else countMon = 12;

		if(isLeapYear(c_year)){
			for(int j = 0; j < countMon; j++){
				allDays = allDays + massLeapMonth[j];
			}
		} else {
			for(int j = 0; j < countMon; j++){
				allDays = allDays + massMonth[j];
			}
		}
		i++;
	}
	seconds = (((((allDays + day) * 24) + hour) * 60 + minute) * 60);
	printf("In Seconds: %ld\n", seconds);

	return 0;
}

bool isLeapYear(int year){
	if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
		return true; 
	} else return false;
}
