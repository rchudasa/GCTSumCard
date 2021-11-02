#ifndef _ALGO_TOP_H_
#define _ALGO_TOP_H_

#include <iostream>
#include "ap_int.h"
#include "ap_utils.h"
#include "bitonicSort32.h"

#define N_GCTCARDS 3 
#define N_GCTtoGCTSum_LINK 2
#define N_EGamma_Object 6

typedef ap_uint<5> loop;
using namespace std;

typedef struct {
ap_uint<14> pt ;
//ap_uint<12> eta ;
//ap_uint<11> phi ;
} EgammaObj_t ;

typedef struct {
EgammaObj_t eGamma[N_EGamma_Object];
}Link_t;

typedef struct {
Link_t link[N_GCTtoGCTSum_LINK];
} GCTcard_t ;

typedef struct {
GCTcard_t ForwardEndCapGCT[N_GCTCARDS] ;
GCTcard_t BackwardEndCapGCT[N_GCTCARDS] ;
GCTcard_t BarrelGCT[N_GCTCARDS] ;
} GCTSumCard_t ;

typedef struct{
Link_t link[N_GCTtoGCTSum_LINK];
}GT_t;

void bitonicSort32(din_t in[N], din_t out[N]);
void algo_top(GCTSumCard_t& GCTsumcard, GT_t& GT) ;

#endif
