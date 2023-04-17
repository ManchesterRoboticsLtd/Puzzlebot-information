@echo off
for /f "tokens=1* delims==" %%I in ('wmic path win32_pnpentity  get caption  /format:list ^| find "CP210x"') do (
	call :setCOM "%%~J"
)
pause
:: end main batch
goto :EOF

:setCOM <WMIC_output_line>
:: sets _COM#=line
set str=%~1
set num=%str:*(COM=%
set num=%num:)=%
set port=COM%num%
echo PuzzleBot found on %port%
echo Enter details for %port%
edit_config.exe
rem Exit this batch file if file config.json does not exist in current directory.
if not exist data/config_default.json goto :EOF
copy data\config_default.json data\config_live.json
spiffsgen.exe 1507328 data spiffs.bin
echo Flashing Firmware
esptool.exe  --port %port% --chip esp32 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0xe000 ../bin/boot_app0.bin 0x1000 ../bin/bootloader_qio_80m.bin 0x10000 ../bin/MainSrc.ino.bin 0x8000 ../bin/MainSrc.ino.partitions.bin
esptool.exe --port %port% --chip esp32 --baud 115200 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0x00290000 spiffs.bin
echo Done!
goto :EOF
pause