#ifndef _am_model_neuron_deltasx_h
#define _am_model_neuron_deltasx_h

int deltasx_model_neuron(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, N_Vector *sx, void *user_data, TempData *tdata);


#endif /* _am_model_neuron_deltasx_h */