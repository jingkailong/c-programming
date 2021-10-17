#include <stdio.h>
#include <stdlib.h>
/* Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing. */
int daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                     {0,31,29,31,30,31,30,31,31,30,31,30,31}};


/** \brief convert to nth day of year
 *
 * \param year
 * \param month
 * \param day
 * \return dayofyear;
 *
 */
 int isleap(int year)
 {
     int leap = ((year % 400 == 0) || ((year % 4 == 0) && (year / 100 != 0)))?1:0;
     return leap;
 }
int year_day(int year,int month,int day)
{
    if ((year < 0) || (month < 0 || month > 12) || (day < 0))
        return -1;
    int dayofyear = 0;
    int i;
    for (i = 1;i < month; i++) /* i = 1 means starting from january */
    {
        dayofyear += daytab[isleap(year)][i];
    }
    dayofyear += day;
    return dayofyear;
}
int month_day(int year,int dayofyear,int* month,int* day)
{
  int leap = ((year % 400 == 0) || ((year % 4 == 0) && (year / 100 != 0)))?1:0;
  int i;
  for (i = 1; dayofyear > daytab[leap][i]; i++)
  {
      dayofyear -= daytab[isleap(year)][i];
  }
  *month = i;
  *day = dayofyear;

  return 0;
}
int main()
{
    #if 0
    int month;
    int day;
    month_day(2021,150,&month,&day); /* will be veried by year_day*/
    printf("%d,%d\n",month,day);
    day = year_day(2021,5,30);       /* will be verified by month_day */
    printf("%d\n",day);
   #endif
    return 0;
}
