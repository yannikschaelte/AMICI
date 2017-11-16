#ifndef amici_newton_solver_h
#define amici_newton_solver_h

#include <klu.h>
#include <nvector/nvector_serial.h> // DlsMat
#include <sundials/sundials_dense.h>
#include <sundials/sundials_sparse.h> // SlsMat

namespace amici {

class UserData;
class ReturnData;
class Model;
class AmiVector;

/**
 * @brief The NewtonSolver class sets up the linear solver for the Newton
 * method.
 */

class NewtonSolver {

  public:
    NewtonSolver(realtype *t, Model *model, ReturnData *rdata, const UserData *udata);

    static NewtonSolver *getSolver(realtype *t, int linsolType, Model *model,
                                   ReturnData *rdata, const UserData *udata);

    void getStep(int ntry, int nnewt, AmiVector *delta);

    void getSensis(int it);

    /**
     * Writes the Jacobian for the Newton iteration and passes it to the linear
     * solver
     *
     * @param[in] ntry integer newton_try integer start number of Newton solver
     * (1 or 2)
     * @param[in] nnewt integer number of current Newton step
     * @return stats integer flag indicating success of the method
     */
    virtual void prepareLinearSystem(int ntry, int nnewt) = 0;

    /**
     * Solves the linear system for the Newton step
     *
     * @param[in,out] rhs containing the RHS of the linear system, will be
     * overwritten by solution to the linear system @type N_Vector
     * @return stats integer flag indicating success of the method
     */
    virtual void solveLinearSystem(AmiVector *rhs) = 0;

  protected:
    realtype *t;
    /** pointer to the AMICI model object */
    Model *model;
    /** pointer to the return data object */
    ReturnData *rdata;
    /** pointer to the user data object */
    const UserData *udata;
    /** sensitivity AmiVector */
    AmiVector sx_ip;
    /** right hand side AmiVector */
    AmiVector xdot;
    /** current state*/
    AmiVector x;
    /** current state time derivative (DAE) */
    AmiVector dx;
    
};

/**
 * @brief The NewtonSolverDense provides access to the dense linear solver for
 * the Newton method.
 */

class NewtonSolverDense : public NewtonSolver {

  public:
    NewtonSolverDense(realtype *t, Model *model, ReturnData *rdata, const UserData *udata);
    void solveLinearSystem(AmiVector *rhs) override;
    void prepareLinearSystem(int ntry, int nnewt) override;
    ~NewtonSolverDense();

  private:
    /** temporary storage of pivot array */
    long int *pivots;
    DlsMat Jtmp;
};

/**
 * @brief The NewtonSolverSparse provides access to the sparse linear solver for
 * the Newton method.
 */

class NewtonSolverSparse : public NewtonSolver {

  public:
    NewtonSolverSparse(realtype *t, Model *model, ReturnData *rdata, const UserData *udata);
    void solveLinearSystem(AmiVector *rhs) override;
    void prepareLinearSystem(int ntry, int nnewt) override;
    ~NewtonSolverSparse();

  private:
    /** klu common storage? */
    klu_common common;
    /** klu symbolic storage? */
    klu_symbolic *symbolic;
    /** klu numeric stoarge? */
    klu_numeric *numeric;
    /** klu status flag  */
    int klu_status = 0;
    SlsMat Jtmp;
};

/**
 * @brief The NewtonSolverIterative provides access to the iterative linear
 * solver for the Newton method.
 */

class NewtonSolverIterative : public NewtonSolver {

  public:
    NewtonSolverIterative(realtype *t, Model *model, ReturnData *rdata,
                          const UserData *udata);
    void solveLinearSystem(AmiVector *rhs);
    void prepareLinearSystem(int ntry, int nnewt);
    void linsolveSPBCG(int ntry,int nnewt, AmiVector *ns_delta);
    ~NewtonSolverIterative();

  private:
    /** number of tries  */
    int newton_try;
    /** number of iterations  */
    int i_newton;
    /** ???  */
    AmiVector ns_p;
    /** ???  */
    AmiVector ns_h;
    /** ???  */
    AmiVector ns_t;
    /** ???  */
    AmiVector ns_s;
    /** ???  */
    AmiVector ns_r;
    /** ???  */
    AmiVector ns_rt;
    /** ???  */
    AmiVector ns_v;
    /** ???  */
    AmiVector ns_Jv;
    /** ???  */
    AmiVector ns_tmp;
    /** ???  */
    AmiVector ns_Jdiag;
};


} // namespace amici

#endif // NEWTON_SOLVER
