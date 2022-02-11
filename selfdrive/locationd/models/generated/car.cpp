#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 5.991464547107981;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with sympy 1.8                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1472911324032837365) {
   out_1472911324032837365[0] = delta_x[0] + nom_x[0];
   out_1472911324032837365[1] = delta_x[1] + nom_x[1];
   out_1472911324032837365[2] = delta_x[2] + nom_x[2];
   out_1472911324032837365[3] = delta_x[3] + nom_x[3];
   out_1472911324032837365[4] = delta_x[4] + nom_x[4];
   out_1472911324032837365[5] = delta_x[5] + nom_x[5];
   out_1472911324032837365[6] = delta_x[6] + nom_x[6];
   out_1472911324032837365[7] = delta_x[7] + nom_x[7];
   out_1472911324032837365[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2585029223436918946) {
   out_2585029223436918946[0] = -nom_x[0] + true_x[0];
   out_2585029223436918946[1] = -nom_x[1] + true_x[1];
   out_2585029223436918946[2] = -nom_x[2] + true_x[2];
   out_2585029223436918946[3] = -nom_x[3] + true_x[3];
   out_2585029223436918946[4] = -nom_x[4] + true_x[4];
   out_2585029223436918946[5] = -nom_x[5] + true_x[5];
   out_2585029223436918946[6] = -nom_x[6] + true_x[6];
   out_2585029223436918946[7] = -nom_x[7] + true_x[7];
   out_2585029223436918946[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5810061186425921220) {
   out_5810061186425921220[0] = 1.0;
   out_5810061186425921220[1] = 0.0;
   out_5810061186425921220[2] = 0.0;
   out_5810061186425921220[3] = 0.0;
   out_5810061186425921220[4] = 0.0;
   out_5810061186425921220[5] = 0.0;
   out_5810061186425921220[6] = 0.0;
   out_5810061186425921220[7] = 0.0;
   out_5810061186425921220[8] = 0.0;
   out_5810061186425921220[9] = 0.0;
   out_5810061186425921220[10] = 1.0;
   out_5810061186425921220[11] = 0.0;
   out_5810061186425921220[12] = 0.0;
   out_5810061186425921220[13] = 0.0;
   out_5810061186425921220[14] = 0.0;
   out_5810061186425921220[15] = 0.0;
   out_5810061186425921220[16] = 0.0;
   out_5810061186425921220[17] = 0.0;
   out_5810061186425921220[18] = 0.0;
   out_5810061186425921220[19] = 0.0;
   out_5810061186425921220[20] = 1.0;
   out_5810061186425921220[21] = 0.0;
   out_5810061186425921220[22] = 0.0;
   out_5810061186425921220[23] = 0.0;
   out_5810061186425921220[24] = 0.0;
   out_5810061186425921220[25] = 0.0;
   out_5810061186425921220[26] = 0.0;
   out_5810061186425921220[27] = 0.0;
   out_5810061186425921220[28] = 0.0;
   out_5810061186425921220[29] = 0.0;
   out_5810061186425921220[30] = 1.0;
   out_5810061186425921220[31] = 0.0;
   out_5810061186425921220[32] = 0.0;
   out_5810061186425921220[33] = 0.0;
   out_5810061186425921220[34] = 0.0;
   out_5810061186425921220[35] = 0.0;
   out_5810061186425921220[36] = 0.0;
   out_5810061186425921220[37] = 0.0;
   out_5810061186425921220[38] = 0.0;
   out_5810061186425921220[39] = 0.0;
   out_5810061186425921220[40] = 1.0;
   out_5810061186425921220[41] = 0.0;
   out_5810061186425921220[42] = 0.0;
   out_5810061186425921220[43] = 0.0;
   out_5810061186425921220[44] = 0.0;
   out_5810061186425921220[45] = 0.0;
   out_5810061186425921220[46] = 0.0;
   out_5810061186425921220[47] = 0.0;
   out_5810061186425921220[48] = 0.0;
   out_5810061186425921220[49] = 0.0;
   out_5810061186425921220[50] = 1.0;
   out_5810061186425921220[51] = 0.0;
   out_5810061186425921220[52] = 0.0;
   out_5810061186425921220[53] = 0.0;
   out_5810061186425921220[54] = 0.0;
   out_5810061186425921220[55] = 0.0;
   out_5810061186425921220[56] = 0.0;
   out_5810061186425921220[57] = 0.0;
   out_5810061186425921220[58] = 0.0;
   out_5810061186425921220[59] = 0.0;
   out_5810061186425921220[60] = 1.0;
   out_5810061186425921220[61] = 0.0;
   out_5810061186425921220[62] = 0.0;
   out_5810061186425921220[63] = 0.0;
   out_5810061186425921220[64] = 0.0;
   out_5810061186425921220[65] = 0.0;
   out_5810061186425921220[66] = 0.0;
   out_5810061186425921220[67] = 0.0;
   out_5810061186425921220[68] = 0.0;
   out_5810061186425921220[69] = 0.0;
   out_5810061186425921220[70] = 1.0;
   out_5810061186425921220[71] = 0.0;
   out_5810061186425921220[72] = 0.0;
   out_5810061186425921220[73] = 0.0;
   out_5810061186425921220[74] = 0.0;
   out_5810061186425921220[75] = 0.0;
   out_5810061186425921220[76] = 0.0;
   out_5810061186425921220[77] = 0.0;
   out_5810061186425921220[78] = 0.0;
   out_5810061186425921220[79] = 0.0;
   out_5810061186425921220[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3213061802903321064) {
   out_3213061802903321064[0] = state[0];
   out_3213061802903321064[1] = state[1];
   out_3213061802903321064[2] = state[2];
   out_3213061802903321064[3] = state[3];
   out_3213061802903321064[4] = state[4];
   out_3213061802903321064[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3213061802903321064[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3213061802903321064[7] = state[7];
   out_3213061802903321064[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3473551645610172121) {
   out_3473551645610172121[0] = 1;
   out_3473551645610172121[1] = 0;
   out_3473551645610172121[2] = 0;
   out_3473551645610172121[3] = 0;
   out_3473551645610172121[4] = 0;
   out_3473551645610172121[5] = 0;
   out_3473551645610172121[6] = 0;
   out_3473551645610172121[7] = 0;
   out_3473551645610172121[8] = 0;
   out_3473551645610172121[9] = 0;
   out_3473551645610172121[10] = 1;
   out_3473551645610172121[11] = 0;
   out_3473551645610172121[12] = 0;
   out_3473551645610172121[13] = 0;
   out_3473551645610172121[14] = 0;
   out_3473551645610172121[15] = 0;
   out_3473551645610172121[16] = 0;
   out_3473551645610172121[17] = 0;
   out_3473551645610172121[18] = 0;
   out_3473551645610172121[19] = 0;
   out_3473551645610172121[20] = 1;
   out_3473551645610172121[21] = 0;
   out_3473551645610172121[22] = 0;
   out_3473551645610172121[23] = 0;
   out_3473551645610172121[24] = 0;
   out_3473551645610172121[25] = 0;
   out_3473551645610172121[26] = 0;
   out_3473551645610172121[27] = 0;
   out_3473551645610172121[28] = 0;
   out_3473551645610172121[29] = 0;
   out_3473551645610172121[30] = 1;
   out_3473551645610172121[31] = 0;
   out_3473551645610172121[32] = 0;
   out_3473551645610172121[33] = 0;
   out_3473551645610172121[34] = 0;
   out_3473551645610172121[35] = 0;
   out_3473551645610172121[36] = 0;
   out_3473551645610172121[37] = 0;
   out_3473551645610172121[38] = 0;
   out_3473551645610172121[39] = 0;
   out_3473551645610172121[40] = 1;
   out_3473551645610172121[41] = 0;
   out_3473551645610172121[42] = 0;
   out_3473551645610172121[43] = 0;
   out_3473551645610172121[44] = 0;
   out_3473551645610172121[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3473551645610172121[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3473551645610172121[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3473551645610172121[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3473551645610172121[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3473551645610172121[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3473551645610172121[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3473551645610172121[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3473551645610172121[53] = -9.8000000000000007*dt;
   out_3473551645610172121[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3473551645610172121[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3473551645610172121[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3473551645610172121[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3473551645610172121[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3473551645610172121[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3473551645610172121[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3473551645610172121[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3473551645610172121[62] = 0;
   out_3473551645610172121[63] = 0;
   out_3473551645610172121[64] = 0;
   out_3473551645610172121[65] = 0;
   out_3473551645610172121[66] = 0;
   out_3473551645610172121[67] = 0;
   out_3473551645610172121[68] = 0;
   out_3473551645610172121[69] = 0;
   out_3473551645610172121[70] = 1;
   out_3473551645610172121[71] = 0;
   out_3473551645610172121[72] = 0;
   out_3473551645610172121[73] = 0;
   out_3473551645610172121[74] = 0;
   out_3473551645610172121[75] = 0;
   out_3473551645610172121[76] = 0;
   out_3473551645610172121[77] = 0;
   out_3473551645610172121[78] = 0;
   out_3473551645610172121[79] = 0;
   out_3473551645610172121[80] = 1;
}
void h_25(double *state, double *unused, double *out_6523909850598095626) {
   out_6523909850598095626[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3116521946452841514) {
   out_3116521946452841514[0] = 0;
   out_3116521946452841514[1] = 0;
   out_3116521946452841514[2] = 0;
   out_3116521946452841514[3] = 0;
   out_3116521946452841514[4] = 0;
   out_3116521946452841514[5] = 0;
   out_3116521946452841514[6] = 1;
   out_3116521946452841514[7] = 0;
   out_3116521946452841514[8] = 0;
}
void h_24(double *state, double *unused, double *out_817381627255028392) {
   out_817381627255028392[0] = state[4];
   out_817381627255028392[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6102156941187514877) {
   out_6102156941187514877[0] = 0;
   out_6102156941187514877[1] = 0;
   out_6102156941187514877[2] = 0;
   out_6102156941187514877[3] = 0;
   out_6102156941187514877[4] = 1;
   out_6102156941187514877[5] = 0;
   out_6102156941187514877[6] = 0;
   out_6102156941187514877[7] = 0;
   out_6102156941187514877[8] = 0;
   out_6102156941187514877[9] = 0;
   out_6102156941187514877[10] = 0;
   out_6102156941187514877[11] = 0;
   out_6102156941187514877[12] = 0;
   out_6102156941187514877[13] = 0;
   out_6102156941187514877[14] = 1;
   out_6102156941187514877[15] = 0;
   out_6102156941187514877[16] = 0;
   out_6102156941187514877[17] = 0;
}
void h_30(double *state, double *unused, double *out_3282956746392914106) {
   out_3282956746392914106[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1411174383674766684) {
   out_1411174383674766684[0] = 0;
   out_1411174383674766684[1] = 0;
   out_1411174383674766684[2] = 0;
   out_1411174383674766684[3] = 0;
   out_1411174383674766684[4] = 1;
   out_1411174383674766684[5] = 0;
   out_1411174383674766684[6] = 0;
   out_1411174383674766684[7] = 0;
   out_1411174383674766684[8] = 0;
}
void h_26(double *state, double *unused, double *out_7564520587636574614) {
   out_7564520587636574614[0] = state[7];
}
void H_26(double *state, double *unused, double *out_624981372421214710) {
   out_624981372421214710[0] = 0;
   out_624981372421214710[1] = 0;
   out_624981372421214710[2] = 0;
   out_624981372421214710[3] = 0;
   out_624981372421214710[4] = 0;
   out_624981372421214710[5] = 0;
   out_624981372421214710[6] = 0;
   out_624981372421214710[7] = 1;
   out_624981372421214710[8] = 0;
}
void h_27(double *state, double *unused, double *out_3741411351641708639) {
   out_3741411351641708639[0] = state[3];
}
void H_27(double *state, double *unused, double *out_812419687509176533) {
   out_812419687509176533[0] = 0;
   out_812419687509176533[1] = 0;
   out_812419687509176533[2] = 0;
   out_812419687509176533[3] = 1;
   out_812419687509176533[4] = 0;
   out_812419687509176533[5] = 0;
   out_812419687509176533[6] = 0;
   out_812419687509176533[7] = 0;
   out_812419687509176533[8] = 0;
}
void h_29(double *state, double *unused, double *out_2339446893491251671) {
   out_2339446893491251671[0] = state[1];
}
void H_29(double *state, double *unused, double *out_900943039360374500) {
   out_900943039360374500[0] = 0;
   out_900943039360374500[1] = 1;
   out_900943039360374500[2] = 0;
   out_900943039360374500[3] = 0;
   out_900943039360374500[4] = 0;
   out_900943039360374500[5] = 0;
   out_900943039360374500[6] = 0;
   out_900943039360374500[7] = 0;
   out_900943039360374500[8] = 0;
}
void h_28(double *state, double *unused, double *out_5125650601372969723) {
   out_5125650601372969723[0] = state[5];
   out_5125650601372969723[1] = state[6];
}
void H_28(double *state, double *unused, double *out_6812230162201768359) {
   out_6812230162201768359[0] = 0;
   out_6812230162201768359[1] = 0;
   out_6812230162201768359[2] = 0;
   out_6812230162201768359[3] = 0;
   out_6812230162201768359[4] = 0;
   out_6812230162201768359[5] = 1;
   out_6812230162201768359[6] = 0;
   out_6812230162201768359[7] = 0;
   out_6812230162201768359[8] = 0;
   out_6812230162201768359[9] = 0;
   out_6812230162201768359[10] = 0;
   out_6812230162201768359[11] = 0;
   out_6812230162201768359[12] = 0;
   out_6812230162201768359[13] = 0;
   out_6812230162201768359[14] = 0;
   out_6812230162201768359[15] = 1;
   out_6812230162201768359[16] = 0;
   out_6812230162201768359[17] = 0;
}
void h_31(double *state, double *unused, double *out_8916581589052790153) {
   out_8916581589052790153[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1251189474654566186) {
   out_1251189474654566186[0] = 0;
   out_1251189474654566186[1] = 0;
   out_1251189474654566186[2] = 0;
   out_1251189474654566186[3] = 0;
   out_1251189474654566186[4] = 0;
   out_1251189474654566186[5] = 0;
   out_1251189474654566186[6] = 0;
   out_1251189474654566186[7] = 0;
   out_1251189474654566186[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1472911324032837365) {
  err_fun(nom_x, delta_x, out_1472911324032837365);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2585029223436918946) {
  inv_err_fun(nom_x, true_x, out_2585029223436918946);
}
void car_H_mod_fun(double *state, double *out_5810061186425921220) {
  H_mod_fun(state, out_5810061186425921220);
}
void car_f_fun(double *state, double dt, double *out_3213061802903321064) {
  f_fun(state,  dt, out_3213061802903321064);
}
void car_F_fun(double *state, double dt, double *out_3473551645610172121) {
  F_fun(state,  dt, out_3473551645610172121);
}
void car_h_25(double *state, double *unused, double *out_6523909850598095626) {
  h_25(state, unused, out_6523909850598095626);
}
void car_H_25(double *state, double *unused, double *out_3116521946452841514) {
  H_25(state, unused, out_3116521946452841514);
}
void car_h_24(double *state, double *unused, double *out_817381627255028392) {
  h_24(state, unused, out_817381627255028392);
}
void car_H_24(double *state, double *unused, double *out_6102156941187514877) {
  H_24(state, unused, out_6102156941187514877);
}
void car_h_30(double *state, double *unused, double *out_3282956746392914106) {
  h_30(state, unused, out_3282956746392914106);
}
void car_H_30(double *state, double *unused, double *out_1411174383674766684) {
  H_30(state, unused, out_1411174383674766684);
}
void car_h_26(double *state, double *unused, double *out_7564520587636574614) {
  h_26(state, unused, out_7564520587636574614);
}
void car_H_26(double *state, double *unused, double *out_624981372421214710) {
  H_26(state, unused, out_624981372421214710);
}
void car_h_27(double *state, double *unused, double *out_3741411351641708639) {
  h_27(state, unused, out_3741411351641708639);
}
void car_H_27(double *state, double *unused, double *out_812419687509176533) {
  H_27(state, unused, out_812419687509176533);
}
void car_h_29(double *state, double *unused, double *out_2339446893491251671) {
  h_29(state, unused, out_2339446893491251671);
}
void car_H_29(double *state, double *unused, double *out_900943039360374500) {
  H_29(state, unused, out_900943039360374500);
}
void car_h_28(double *state, double *unused, double *out_5125650601372969723) {
  h_28(state, unused, out_5125650601372969723);
}
void car_H_28(double *state, double *unused, double *out_6812230162201768359) {
  H_28(state, unused, out_6812230162201768359);
}
void car_h_31(double *state, double *unused, double *out_8916581589052790153) {
  h_31(state, unused, out_8916581589052790153);
}
void car_H_31(double *state, double *unused, double *out_1251189474654566186) {
  H_31(state, unused, out_1251189474654566186);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
