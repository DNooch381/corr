echo WARNING this program will overwrite any existing aggregated output
echo You have 5 seconds to prevent this from happening...
sleep 5
echo Okay, proceeding...
sleep 1

hadd -f -k SumFile_k2.root OutFile_*_k2.root
hadd -f -k SumFile_k4.root OutFile_*_k4.root
hadd -f -k SumFile_k6.root OutFile_*_k6.root
hadd -f -k SumFile_k8.root OutFile_*_k8.root

