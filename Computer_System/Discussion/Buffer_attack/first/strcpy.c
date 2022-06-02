
 /*
GNU-C中的实现（节选）：
*/
char* strcpy(char *d, const char *s)
{
  char *r=d;
  while((*d++=*s++));
  return r;
}