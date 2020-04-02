# Toy Monte Carlo for UNCG combinatorics research

## These are the main files and directories for this project

File name | description
--------- | -----------
RanGenX.C | 2,4,6,8 particle Monte Carlo, spacing set to a small value to generate the 2nd harmonic for all correlators
RanGen2X.C | 2,4,6,8 particle Monte Carlo, spacing set to 2pi/k to generate k-th harmonic for k-th correlator
RanGen2B.C | 2,4,6,8 particle Binary correlator, identically matches pure combinatorial expectations
do_rangenX.C | Main code to run RanGenX.C
rng_binary.C | Plots the binary correlations
rng_cumulant.C | Plots the cumulants
rng_histX.C | Plots the ouput from RanGenX.C
rng_hist2X.C | Plots the output from RanGen2X.C
phenix_dcorr.csh | C shell script to run the code in the PHENIX environment
sphenix_dcorr.csh | C shell script to run the code in the sPHENIX environment

## Additional files

File name | description
---------------- | -----------
CondorOutput/SumFile_k2.root | 2 particle event data generated by the RanGenX.C Monte Carlo, run at Brookhaven
CondorOutput/SumFile_k4.root | 4 particle event data generated by the RanGenX.C Monte Carlo, run at Brookhaven
CondorOutput/SumFile_k6.root | 6 particle event data generated by the RanGenX.C Monte Carlo, run at Brookhaven
CondorOutput/SumFile_k8.root | 8 particle event data generated by the RanGenX.C Monte Carlo, run at Brookhaven
CondorOutput/TrialXXXX/SumFile_k2.root | Same as above, but specific trial
CondorOutput/TrialXXXX/SumFile_k4.root | Same as above, but specific trial
CondorOutput/TrialXXXX/SumFile_k6.root | Same as above, but specific trial
CondorOutput/TrialXXXX/SumFile_k8.root | Same as above, but specific trial
OutputFiles/OutFile2_k2.root | 2 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k4.root | 4 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k6.root | 6 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k8.root | 8 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2X_k2.root | 2 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k4.root | 4 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k6.root | 6 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k8.root | 8 particle event data generated by the RanGen2X.C Monte Carlo



## Directories

CondorOutput | Where the condor output is stored
OutputFiles | Where the output from single runs go

