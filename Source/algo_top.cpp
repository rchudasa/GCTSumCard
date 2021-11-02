#include "algo_top.h"

void algo_top(GCTSumCard_t& GCTSum, GT_t& GT){
#pragma HLS ARRAY_PARTITION variable=GCTSum complete dim=0
#pragma HLS PIPELINE II=6
	din_t in_pt_pos_eta[32];
	din_t in_pt_neg_eta[32];
	din_t out_pt_pos_eta[32];
	din_t out_pt_neg_eta[32];

	for(int i=0; i<N_GCTCARDS; i++){
		for(int k=0; k<N_EGamma_Object; k++){
		#pragma HLS unroll
			int id = N_EGamma_Object * i + k;
    		in_pt_pos_eta[id] = GCTSum.BarrelGCT[i].link[0].eGamma[k].pt;
    		in_pt_neg_eta[id] = GCTSum.BarrelGCT[i].link[1].eGamma[k].pt;
		}
	}

	for(int id=18; id<32; id++){
		in_pt_pos_eta[id]=0;
		in_pt_neg_eta[id]=0;
	}

	bitonicSort32(in_pt_pos_eta, out_pt_pos_eta);
	bitonicSort32(in_pt_neg_eta, out_pt_neg_eta);

#pragma HLS ARRAY_PARTITION variable=GT complete dim=0

	for (int i = 0; i <6; i++){
#pragma HLS unroll
	    int id  = 31-i;
		GT.link[0].eGamma[i].pt = out_pt_pos_eta[id];
		GT.link[1].eGamma[i].pt = out_pt_neg_eta[id];
	}
}
