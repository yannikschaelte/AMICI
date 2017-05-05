
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/udata_accessors.h>
#include "model_steadystate_w.h"

int dwdp_model_steadystate(realtype t, N_Vector x, N_Vector dx, void *user_data) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
memset(dwdp_tmp,0,sizeof(realtype)*1);
status = w_model_steadystate(t,x,NULL,user_data);
  dwdp_tmp[0] = x_tmp[2];
return(status);

}


