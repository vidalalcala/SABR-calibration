
// Author: Dimitri Reiswich
#include<boost/math/distributions.hpp>

Real blackScholesPriceFwd(const Real& fwd, 
						 const Real& strike,
						 const Volatility& vol,
						 const Rate& rd,
						 const Rate& rf,
						 const Time& tau,
						 const Integer& phi){
	boost::math::normal_distribution<> d(0.0,1.0);
	Real dp,dm, stdDev, res, domDf, forDf;

	domDf=std::exp(-rd*tau); forDf=std::exp(-rf*tau);
	stdDev=vol*std::sqrt(tau);

	dp=(std::log(fwd/strike)+0.5*stdDev*stdDev)/stdDev;
	dm=(std::log(fwd/strike)-0.5*stdDev*stdDev)/stdDev;

	res=phi*domDf*(fwd*cdf(d,phi*dp)-strike*cdf(d,phi*dm));
	return res;
}
