
typedef  int data_t;
typedef int* vec_ptr;
void inner5 (vec_ptr x,vec_ptr y,data_t *dest)
{
 long int i;
 int length = vec_length(x);
 data_t *xdata = get_vec_start(x);
 data_t *ydata = get_vec_start(y);
 data_t sum0 = (data_t)0;
data_t sum1 = (data_t)0;
data_t sum2 = (data_t)0;
 long int limit = length-2;
 for(i=0;i<limit;i+=3)
 {
  sum0 = sum0 +xdata[i]*ydata[i];
  sum1 = sum1 +xdata[i+1]*ydata[i+1];
  sum2 = sum2 +xdata[i+2]*ydata[i+2];
 }
 for(;i<length ;i++)
 {
 sum0 = sum0 + xdata[i]*ydata[i]; 
 }
 *dest = sum0+sum1+sum2;
}