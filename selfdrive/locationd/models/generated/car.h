#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1472911324032837365);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2585029223436918946);
void car_H_mod_fun(double *state, double *out_5810061186425921220);
void car_f_fun(double *state, double dt, double *out_3213061802903321064);
void car_F_fun(double *state, double dt, double *out_3473551645610172121);
void car_h_25(double *state, double *unused, double *out_6523909850598095626);
void car_H_25(double *state, double *unused, double *out_3116521946452841514);
void car_h_24(double *state, double *unused, double *out_817381627255028392);
void car_H_24(double *state, double *unused, double *out_6102156941187514877);
void car_h_30(double *state, double *unused, double *out_3282956746392914106);
void car_H_30(double *state, double *unused, double *out_1411174383674766684);
void car_h_26(double *state, double *unused, double *out_7564520587636574614);
void car_H_26(double *state, double *unused, double *out_624981372421214710);
void car_h_27(double *state, double *unused, double *out_3741411351641708639);
void car_H_27(double *state, double *unused, double *out_812419687509176533);
void car_h_29(double *state, double *unused, double *out_2339446893491251671);
void car_H_29(double *state, double *unused, double *out_900943039360374500);
void car_h_28(double *state, double *unused, double *out_5125650601372969723);
void car_H_28(double *state, double *unused, double *out_6812230162201768359);
void car_h_31(double *state, double *unused, double *out_8916581589052790153);
void car_H_31(double *state, double *unused, double *out_1251189474654566186);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}