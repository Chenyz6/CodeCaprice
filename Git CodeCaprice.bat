@echo off
@title bat 交互执行git命令
cd E:\Desktop\CodeCaprice
git add .
git commit -m %date:~0,4%.%date:~5,2%.%date:~8,2%
git push origin main