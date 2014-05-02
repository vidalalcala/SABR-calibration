// Author: Jose V. Alcala-Burgos
class SimpleVolQuote: public Quote{
private:
	Volatility vol_;
	Real strike_;

public:
	SimpleVolQuote(Volatility vol, Real strike) :vol_(vol),strike_(strike){}

	bool isValid() const {return vol_!=Null<Real>();}
	Real value() const {return vol_;}
	Real strike()const {return strike_;}

	void setVolatility(const Volatility& vol){
		vol_=vol;
		notifyObservers();	
	}	 
};
class SimpleSmile: public Observable, Observer{
private:
	std::vector<boost::shared_ptr<SimpleVolQuote> > volVec_;
public:
	SimpleSmile(const std::vector<boost::shared_ptr<SimpleVolQuote> >& volVec)
		:volVec_(volVec){
		for(Size i=0;i<volVec_.size();i++){
			registerWith(volVec_[i]);
		}
	}
	void update(){
		notifyObservers();
	}

	std::vector<boost::shared_ptr<SimpleVolQuote> > getVolVec() const{return volVec_;}
	Size getVolNumber() const{return volVec_.size();}
};