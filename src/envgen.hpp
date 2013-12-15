#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

float* gen_full_envelope(int Size, int Attack, int Release);
float* gen_attack(int Attack);
float* gen_release(int Release);
float* gen_release(float StartingAmp, int Release);
float* gen_long_release(int Size, int Release);

#endif

