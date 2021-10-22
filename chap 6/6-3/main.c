#include <stdio.h>
#include <stdlib.h>



#define _CRASH_ON_ERROR_TRACE(uTrId, str, ...) \
  printf("Crash on error trace <!" #uTrId "!> " str, __VA_ARGS__)

#define TRACE_ERROR_NO_UID(str,...)        _CRASH_ON_ERROR_TRACE(0,str, __VA_ARGS__)

int main()
{
    TRACE_ERROR_NO_UID("aa",0);
    return 0;
}
