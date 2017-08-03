#ifndef _amici_wrapfunctions_h
#define _amici_wrapfunctions_h
#include <math.h>

#include "model_steadystate.h"

class UserData;
class Solver;


#define pi M_PI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

UserData getUserData();
Solver *getSolver();
int fx0(N_Vector x0, void *user_data);
int fdx0(N_Vector x0, N_Vector dx0, void *user_data);
int fsx0(N_Vector *sx0, N_Vector x, N_Vector dx, void *user_data);
int fsdx0(N_Vector *sdx0, N_Vector x, N_Vector dx, void *user_data);
int fJ(long int N, realtype t, realtype cj, N_Vector x, N_Vector dx, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJB(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int froot(realtype t, N_Vector x, N_Vector dx, realtype *root, void *user_data);
int frz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, ReturnData *rdata);
int fsrz(realtype t, int ie, N_Vector x, N_Vector *sx, void *user_data, TempData *tdata, ReturnData *rdata);
int fstau(realtype t, int ie, N_Vector x, N_Vector *sx, void *user_data, TempData *tdata);
int fy(realtype t, int it, N_Vector x, void *user_data, ReturnData *rdata);
int fdydp(realtype t, int it, N_Vector x, void *user_data, TempData *tdata);
int fdydx(realtype t, int it, N_Vector x, void *user_data, TempData *tdata);
int fz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, ReturnData *rdata);
int fsz(realtype t, int ie, N_Vector x, N_Vector *sx, void *user_data, TempData *tdata, ReturnData *rdata);
int fdzdp(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata);
int fdzdx(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata);
int fdrzdp(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata);
int fdrzdx(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata);
int fsxdot(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip,  N_Vector sx, N_Vector sxdot, void *user_data, N_Vector tmp1, N_Vector tmp2);
int fxdot(realtype t, N_Vector x, N_Vector dx, N_Vector xdot, void *user_data);
int fxBdot(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data);
int fqBdot(realtype t, N_Vector x, N_Vector xB, N_Vector qBdot, void *user_data);
int fdxdotdp(realtype t, N_Vector x, N_Vector dx, void *user_data);
int fdeltax(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, void *user_data, TempData *tdata);
int fdeltasx(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, void *user_data, TempData *tdata);
int fdeltaxB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector xdot, N_Vector xdot_old, void *user_data, TempData *tdata);
int fdeltaqB(realtype t, int ie, N_Vector x, N_Vector xB, N_Vector qBdot, N_Vector xdot, N_Vector xdot_old, void *user_data, TempData *tdata);
int fsigma_y(realtype t, void *user_data, TempData *tdata);
int fdsigma_ydp(realtype t, void *user_data, TempData *tdata);
int fsigma_z(realtype t, int ie, void *user_data, TempData *tdata);
int fdsigma_zdp(realtype t, int ie, void *user_data, TempData *tdata);
int fJSparse(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJBand(long int N, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xdot, DlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
int fJv(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp);
int fJSparseB(realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, SlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJBandB(long int NeqBdot, long int mupper, long int mlower, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B);
int fJvB(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB);
int fJy(realtype t, int it, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fJrz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydy(realtype t, int it, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJydsigma(realtype t, int it, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJzdsigma(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdz(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
int fdJrzdsigma(realtype t, int ie, N_Vector x, void *user_data, TempData *tdata, const ExpData *edata, ReturnData *rdata);
#endif /* _amici_wrapfunctions_h */
