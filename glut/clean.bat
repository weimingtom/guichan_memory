del /S /Q *.ncb *.opt *.plg
rmdir /S /Q Release Debug
del stderr.txt
del stdout.txt

cd guichan
call clean.bat
cd ..
