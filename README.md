# Toy Monte Carlo for UNCG combinatorics research

## These are the main files and directories for this project

File name | description
--------- | -----------
rnghist2X.C | Functions for plotting recursion data
rnghistXR.C | TFiles and Histograms for the 2, 4, 6, and 8 particle data runs
RanGenX.C | 2,4,6,8 particle Monte Carlo w/out const double pi code line. Edit "int howmany = " to change the event amount.
RanGen2X.C | 2,4,6,8 particle Monte Carlo w/ const double pi code line. Edit "int howmany = "	to change the event amount.
RanGen2B.C | 2,4,6,8 particle Binary correlator. Edit "int howmany = "	to change the event amount.

## Additional files

File name | description
---------------- | -----------
OutputFiles/OutFile2_k2.root | 2 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k4.root | 4 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k6.root | 6 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2_k8.root | 8 particle event data generated by the RanGenX.C Monte Carlo
OutputFiles/OutFile2X_k2.root | 2 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k4.root | 4 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k6.root | 6 particle event data generated by the RanGen2X.C Monte Carlo
OutputFiles/OutFile2X_k8.root | 8 particle event data generated by the RanGen2X.C Monte Carlo

## Directories

**Corr** - Working area for the 2, 4, 6, 8 particle correlation analysis