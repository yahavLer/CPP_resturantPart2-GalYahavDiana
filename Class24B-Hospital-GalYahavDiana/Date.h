#pragma once
#ifndef __DATE_H
#define __DATE_H

class Date 
{
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const;
    bool isValidDate(int day, int month, int year) const;

public:
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};

#endif // __DATE_H