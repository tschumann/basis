:: make sure the remote is correct
git remote rm valve
git remote add valve https://github.com/ValveSoftware/halflife
:: pull in the latest upstream changes
git pull valve master

pause