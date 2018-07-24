#ifndef TBGOHIT_H
#define TBGOHIT_H

/** \addtogroup Detectors
 *  @{
 */

#include <cstdio>
#include <cmath>
#if !defined(__CINT__) && !defined(__CLING__)
#include <tuple>
#endif

#include "TMath.h"
#include "TVector3.h"
#include "TClonesArray.h"

#include "TFragment.h"
#include "TChannel.h"
#include "TPulseAnalyzer.h"

#include "TDetectorHit.h"

class TBgoHit : public TDetectorHit {
public:
   TBgoHit();
   TBgoHit(const TBgoHit&);
   TBgoHit(const TFragment& frag) : TDetectorHit(frag) {}
   ~TBgoHit() override;

   /////////////////////////		/////////////////////////////////////
   int GetCrystal() const override;
   inline UShort_t GetArrayNumber() const override { return (20 * (GetDetector() - 1) + 5 * GetCrystal() + GetSegment()); } //!<!

   void Clear(Option_t* opt = "") override;       //!<!
   void Copy(TObject&) const override;            //!<!
   void Print(Option_t* opt = "") const override; //!<!

   /// \cond CLASSIMP
   ClassDefOverride(TBgoHit, 1)
   /// \endcond
};
/*! @} */
#endif
