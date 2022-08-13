#include <stdio.h>
struct Calendar{
    unsigned int year;
    unsigned short int mon;
    unsigned short int day;
};

bool leapYear(unsigned int year){
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
        return true;
    }
    else{
        return false;
    }
}

void nextDay(struct Calendar *calender){
    unsigned short int dayEnd[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(leapYear(calender->year)){
        dayEnd[1] = 29;
    }
    calender->day++;
    if(calender->day > dayEnd[calender->mon - 1]){
        calender->day = 1;
        calender->mon++;
        if(calender->mon > 12){
            calender->mon = 1;
            calender->year++;
        }
    }
}



int main(){
    struct Calendar calender = {2022, 4, 28};
    int count = 10000;
    while(count--){
        nextDay(&calender);
    }
    printf("%d, %d, %d\n", calender.year, calender.mon, calender.day);
    return 0;
}
