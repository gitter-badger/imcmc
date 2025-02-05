=====
imcmc
=====
:imcmc: A C++ implemented MCMC library
:Version: 0.1.1
:Author: Youhua Xu
:Homepage: http://lss.bao.ac.cn/~xyh/

Description
============

This code aims to provide easy to use interfece to MCMC simulations.  Currently only 
the Affine-Invariant Ensemble Sampler algorithm has been implemented, in the future 
other commonly used algorithms / samplers will also be included into this library, 
for example the classical Metropolis-Hastings and Hamiltonian Monte Carlo. Besides I
would also like to add an interface to MultiNest.

Updates
=========
Oct-31-2015:
------------
1) Bug-fixed inside update_a_walker(***)

Oct-28-2015: 
---------------
1) Added likelihood error handling option, i.e., whether stop when an error happends
inside likelihood function; and now the sampler support writing derived parameters 
into chain files, by design, these derived parameters are to be calculated inside 
the likelihood functions, so that's up to the users. 'gaussian.cpp' in examples shows
 to use derived parameters.

Oct-19-2015: 
---------------
1) Some minor improvements

Oct-18-2015:
--------------
1) Updated the output format, the same as CosmoMC. 
2) keyword 'chain_size' is replaced by sample_step. 

Dependence
============
1) OpenMPI
2) GSL (using only GSL's random number generator)
