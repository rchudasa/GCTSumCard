#include "algo_top.h"
#include <cstdlib>

int main(){

	GCTSumCard_t GCTSum ;

    srand((unsigned)time(0));


	for(int i=0; i<N_GCTCARDS; i++){
		for(int k=0; k<N_EGamma_Object; k++){
			int id = N_EGamma_Object * i + k;
    		GCTSum.BarrelGCT[i].link[0].eGamma[k].pt = 0;
    		GCTSum.BarrelGCT[i].link[1].eGamma[k].pt = 0;
		}
	}

	GCTSum.BarrelGCT[0].link[0].eGamma[0].pt = 13;
	GCTSum.BarrelGCT[0].link[0].eGamma[1].pt = 8;
	GCTSum.BarrelGCT[0].link[0].eGamma[2].pt = 76;
	GCTSum.BarrelGCT[0].link[0].eGamma[3].pt = 21;
	GCTSum.BarrelGCT[0].link[0].eGamma[4].pt = 45;
	GCTSum.BarrelGCT[0].link[0].eGamma[5].pt = 10;

	GCTSum.BarrelGCT[1].link[0].eGamma[0].pt = 20;
	GCTSum.BarrelGCT[1].link[0].eGamma[1].pt = 88;
	GCTSum.BarrelGCT[1].link[0].eGamma[2].pt = 22;
	GCTSum.BarrelGCT[1].link[0].eGamma[3].pt = 33;
	GCTSum.BarrelGCT[1].link[0].eGamma[4].pt = 44;
	GCTSum.BarrelGCT[1].link[0].eGamma[5].pt = 55;

	GCTSum.BarrelGCT[2].link[0].eGamma[0].pt = 47;
	GCTSum.BarrelGCT[2].link[0].eGamma[1].pt = 29;
	GCTSum.BarrelGCT[2].link[0].eGamma[2].pt = 5;
	GCTSum.BarrelGCT[2].link[0].eGamma[3].pt = 100;
	GCTSum.BarrelGCT[2].link[0].eGamma[4].pt = 37;
	GCTSum.BarrelGCT[2].link[0].eGamma[5].pt = 52;

    GT_t GT ;
    
    algo_top(GCTSum,GT);

	for (int i = 0; i < 6; i++){
		cout << "pt to Global trigger is:" << GT.link[0].eGamma[i].pt << endl;
	}
    return 0;

}
