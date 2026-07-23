// Project Euler: 19
// Counting Sundays

#include <iostream>
#include <string>
#include <vector>

int month_days(std::string month, int year) {
  if(month == "Sep" || month == "Apr" || month == "Jun" || month == "Nov") {
    return 30;
  } else if(month == "Feb") {
    if(year%100 == 0 && year%400 == 0) return 29;
    if(year%100 != 0 && year%4 == 0) return 29;
    return 28;
  } else {
    return 31;
  }
}

int main() {
  std::vector<std::string> weeks  = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  std::vector<std::string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  int week  = 1;
  int month = 0;

  int day   = 1;
  int year = 1900;

  int num_sundays = 0;

  while(year < 1901) {
    if(week == weeks.size() - 1) week = 0;
    else ++week;

    if(day == month_days(months[month], year)) {
      if(month == months.size() - 1) {
        ++year;
        month = 0;
      } else {
        ++month;
      }
      day = 1;
    } else {
      ++day;
    }
  }

  while(year <= 2000) {
    if(weeks[week] == "Sun" && day == 1) ++num_sundays;

    if(week == weeks.size() - 1) week = 0;
    else ++week;

    if(day == month_days(months[month], year)) {
      if(month == months.size() - 1) {
        ++year;
        month = 0;
      } else {
        ++month;
      }
      day = 1;
    } else {
      ++day;
    }
  }

  std::cout << num_sundays << std::endl;
}