for port in ls -1 /dev/tty*
do
	if [[ $port == *"usbserial"* ]]; then
		echo PuzzleBot found on $port
		echo enter details for $port
		python edit_config.py
		copy data/config_default.json data/config_live.json
		python spiffsgen.py 1507328 data spiffs.bin
		echo Flashing Firmware
		./esptool --port $port --chip esp32 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0xe000 ../bin/boot_app0.bin 0x1000 ../bin/bootloader_qio_80m.bin 0x10000 ../bin/MainSrc.ino.bin 0x8000 ../bin/MainSrc.ino.partitions.bin

		./esptool --port $port --chip esp32 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0x00290000 ../bin/MainSrc.spiffs.bin 
		echo Done!
	fi
	
done  
