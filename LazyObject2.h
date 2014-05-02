
// Author: Jose V. Alcala-Burgos

#include "LazyObject1.h"
#include "LazyObjectBS.h"

class SabrModel: public LazyObject{

public:
	SabrModel(const boost::shared_ptr<SimpleSmile>& smile,
		const Real& fwd, const Time& tau, const Real& rd,const Real& rf)
		:smile_(smile),fwd_(fwd),tau_(tau),rd_(rd),rf_(rf),
		strikeVec_	(std::vector<Real>(smile->getVolNumber())),
		volVec_		(std::vector<Real>(smile->getVolNumber())){
			// register smile as observable
			registerWith(smile_);
	}
	
	Real getVanillaPrice(const Real& strike){
		calculate();
		return blackScholesPriceFwd(fwd_,strike,(*intp_)(strike),rd_,rf_,tau_,1);
	}

private:
	
	void performCalculations() const{
		volQuoteVec_=smile_->getVolVec();	
		for(Size i=0;i< volQuoteVec_.size();++i){
			strikeVec_[i]=(*volQuoteVec_[i]).strike();
			volVec_[i]=(*volQuoteVec_[i]).value();
		}		

		if(intp_==NULL){
			intp_.reset(new SABRInterpolation(strikeVec_.begin(), strikeVec_.end(), 
			volVec_.begin(),tau_,fwd_,0.1,0.1,0.1,0.1,false, false, false, false));
		}
			intp_->update(); std::cout << "Recalibration Performed!" << std::endl;
	
	}

	Real fwd_,rd_,rf_;
	Time tau_;
	boost::shared_ptr<SimpleSmile> smile_;
	mutable boost::shared_ptr<SABRInterpolation> intp_;
	mutable std::vector<Real> strikeVec_,volVec_;
	mutable std::vector<boost::shared_ptr<SimpleVolQuote> > volQuoteVec_;
};

