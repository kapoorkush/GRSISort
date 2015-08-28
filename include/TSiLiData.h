#ifndef __SiLiDATA__
#define __SiLiDATA__


#include "TFragment.h"
#include "TChannel.h"
#include "TGRSIDetectorData.h"

#include <vector>

class TSiLiData : public TGRSIDetectorData {

  private:
    std::vector<UShort_t>    fSiLiSegment;
    std::vector<TFragment> fSiLiFragment;
   
 public:
    TSiLiData();
    ~TSiLiData();

    void Clear(Option_t *opt = ""); //!
    void Print(Option_t *opt = "") const; //!

    inline void SetSegment(Int_t fSeg)    { fSiLiSegment.push_back((UShort_t) fSeg);   } //!
    inline void SetFragment(TFragment &fFrag) { fSiLiFragment.push_back(fFrag); } //!
        

    inline void SetSiLi(TFragment *frag,TChannel *channel, MNEMONIC *mnemonic )  {
      if(!frag||!channel||!mnemonic)
         return;
      char seg[5]; 
      strncpy(seg,channel->GetChannelName()+7,3);
      SetSegment(atoi(seg));  
      SetFragment(*frag);  
    }

    inline UInt_t  GetMultiplicity()  {return  fSiLiSegment.size();  }

    inline UShort_t  GetSegment(UInt_t &i)  {  return fSiLiSegment.at(i);  }  //!
    inline TFragment GetFragment(UInt_t &i) {  return fSiLiFragment.at(i);  }  //!

};

#endif