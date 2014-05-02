
// Author: Jose V. Alcala-Burgos
#include "LazyObject2.h"

void testingLazyObject1(){

	boost::shared_ptr<SimpleVolQuote> v1(new SimpleVolQuote(0.20, 90.0)); 
	boost::shared_ptr<SimpleVolQuote> v2(new SimpleVolQuote(0.194,95.0)); 
	boost::shared_ptr<SimpleVolQuote> v3(new SimpleVolQuote(0.187,100.0)); 
	boost::shared_ptr<SimpleVolQuote> v4(new SimpleVolQuote(0.191,105.0)); 
		
	std::vector<boost::shared_ptr<SimpleVolQuote> > volVec;

	volVec.push_back(v1); volVec.push_back(v2);
	volVec.push_back(v3); volVec.push_back(v4);

	boost::shared_ptr<SimpleSmile> mySmile(new SimpleSmile(volVec));

	Time tau=0.5; Real spot=100.0, rd=0.03, rf=0.024;
	Real fwd=spot*std::exp((rd-rf)*tau);

	SabrModel myModel(mySmile, fwd, tau, rd, rf);

	Real res=myModel.getVanillaPrice(100.0);
	std::cout << "Initial Sabr ATM Vanilla Price:" << res << std::endl;
	res=myModel.getVanillaPrice(90.0);
	res=myModel.getVanillaPrice(95.0);
	res=myModel.getVanillaPrice(105.0);

	v1->setVolatility(0.22);
	v2->setVolatility(0.214);
	v3->setVolatility(0.207);
	v4->setVolatility(0.211);

	res=myModel.getVanillaPrice(100.0);
	std::cout << "Last Sabr ATM Vanilla Price:" << res << std::endl;
}
