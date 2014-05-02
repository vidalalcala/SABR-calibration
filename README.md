SABR-calibration
================

Calibration of Hagan'a SABR stochastic volatility model using QuantLib. This code is based on Dimitri Reiswich's [course slides](http://quantlib.org/slides/dima-ql-intro-1.pdf).

Requirements
------------

* Unix environment

* [QuantLib library](http://quantlib.org/) 

Running
-------

    $ c++ sabrCalibration.cpp -o sabr_Calibration -lQuantLib
	$ ./sabr_Calibration
