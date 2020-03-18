Scenario : a communications system where agents exchange timestamped data to do with data acquisition that is measured from what ought to be a common reset t0.

Problem : if one agent gets out of synch with the network, recipients of the data that is too old need to detect and discard it.

Portability Issue : the first solution to this problem uses an absolute value function to ensure appropriate signedness, but this function is not portable across even common versions of gcc (4.8.5 to 7.0)

NB : to inspect the C preprocessor intermediate phase, assuming a make target, in the build directory, try "make maxage.cpp.i" and then look for the generated .i file.

 
