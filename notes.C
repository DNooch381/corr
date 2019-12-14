Updated:  12/14/19:

Files:

README.md

rnghistX.C
rnghist2X.C
rnghistXR.C
RanGenX.C
RanGen2X.C


Entering Corr directory

Open a Repo
cd Repo Name (Ex: cp Corr)

Committing Changes to GitHub

cp Repository name (Ex: cp Corr)
git add File name (Ex: git add RanGen2.C)
git commit -m ‘comment on changes’ (Ex: git commit -m ‘updated headers’)
git push

Pull changes

git pull

Linking to GitHub:

sudo /usr/libexec/locate.updatedb
Password: computer password
locate file name
git clone https://github.com/DNooch381/Corr.git
cd repo name
ls
git status
git push -u origin master

Viewing OneFile Histo Data from last run
root -l Filename.root
.ls
hmult_recursion_0_0->Draw()

Run TCanvas w. test.C

To run it just do:
root -l test.C

To quite session:
.q

Viewing Code Changes After Git Pull

git diff insert alphanumeric string next to ‘updating’ (Ex: git diff 40a9be3..d1e5987)


Output Files:

OutputFiles/OutFile2X_k2.root
