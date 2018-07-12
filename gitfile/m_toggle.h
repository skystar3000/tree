#ifndef __M_TOGGLE_H
#define __M_TOGGLE_H


#define Toggler_angle_zero 	1*8192/360*36
#define Toggler_angle_one 	45*8192/360*36
#define Toggler_angle_two 	90*8192/360*36

extern float Toggler_ang_set;

extern void Toggler_ctr(void);
extern void Toggler_error_ctr(void);
#endif

