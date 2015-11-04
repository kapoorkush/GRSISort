#ifndef TRF_PHASE_H
#define TRF_PHASE_H


#include <vector>
#include <iostream>
#include <stdio.h>

#include "TMath.h"
#include "TDetector.h"
#include "TPulseAnalyzer.h"

#include "TFragment.h"

static const Double_t period_ns=84.409;

class TRF :  public TDetector {
		
	public:
	
	TRF();
	TRF(const TRF&);
	virtual ~TRF();
		
	Double_t TimeSFU()const     { return ((timesfu/period_ns)-(int)((timesfu/period_ns)*2.0))*-2*period_ns; }
	Long_t   TimeStamp() const  { return timestamp; }	
	time_t   MidasTime() const  { return midastime; }
	Double_t Time() const       { 
					if(timesfu>period_ns*0.5)	
					return (1-(timesfu/period_ns))*2*period_ns;
					else return timesfu*-2;
				    }
	Double_t Phase() const      { 	
					if(timesfu>period_ns*0.5)
					return (1-(timesfu/period_ns))*TMath::TwoPi();
					else return(timesfu/period_ns)*-TMath::TwoPi();
				    }
	
	
	void BuildHits(TDetectorData *data=0, Option_t * = "");
	void FillData(TFragment*,TChannel*,MNEMONIC*);	
	
	void Copy(TObject&) const;
	void Clear(Option_t *opt = ""); 	 
	void Print(Option_t *opt = "") const;

	private:

        time_t midastime;
        Long_t timestamp;
	double timesfu;
		
	ClassDef(TRF,3)

};



#endif
