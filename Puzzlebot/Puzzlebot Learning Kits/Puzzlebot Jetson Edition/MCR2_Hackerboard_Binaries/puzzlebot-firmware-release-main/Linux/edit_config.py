import json
from argparse import ArgumentParser
parser = ArgumentParser(description="Edit the SSID and password in the config to be flashed the puzzlebot")
parser.add_argument("-d","--default",dest="use_defaults", help="Use default values for SSID and password. -s and -p arguments will be ignored",action='store_true')
parser.add_argument("-s","--ssid",dest="ssid", help="Input SSID")
parser.add_argument("-p","--pasword",dest="password", help="Input Password")
parser.add_argument("-b", "--bulk",dest="bulk",help="Takes the SSIDs and passwords from text files (SSID.txt and Password.txt). All other arguments will be ignored",action='store_true')
args = parser.parse_args()
if args.bulk:
    print("Using SSIDs and passwords from text files, ignoring all other command-line arguments")
    try:
        ssid_file = open('ssid.txt','r')
    except IOError:
        print("Error, ssid.txt not found")
        exit()
    ssids = [line.rstrip() for line in ssid_file]
    try:
        password_file = open('password.txt','r')
    except:
        print("Error, password.txt not found")
        exit()
    passwords = [line.rstrip() for line in password_file]
    if not ssids:
        print("Error, blank SSID file detected")
        exit()
    if not passwords:
        print("ERROR: Blank Password file detected")
        exit()
    SSID = ssids[0]
    Password = passwords[0]
    del ssids[0]
    del passwords[0]
    with open('ssid.txt','w') as ssid_file:
        ssid_file.truncate(0)
        [ssid_file.write(element + "\n") for element in ssids]
    with open('password.txt','w') as password_file:
        password_file.truncate(0)
        [password_file.write(element + "\n") for element in passwords]

else:
    if (args.use_defaults and args.ssid) or (args.use_defaults and args.password):
        print("WARNING: custom values entered with use_defaults flag set. Custom values will be ignored")
    if args.use_defaults:
        SSID = "Puzzlebot"
        Password = "Puzzlebot72"
    else:
        if args.ssid:
            SSID = str(args.ssid)
        else:
            SSID = input("Input SSID, leave blank for default SSID (Puzzlebot): ",)
            if SSID == "":
                SSID = "Puzzlebot"
        if args.password:
            Password = str(args.password)
        else:
            Password = input("Enter password, leave blank for default password (Puzzlebot72): ")
            if Password == "":
                Password = "Puzzlebot72"
try:
    file = open('data/config_default.json','r+')
except IOError:
    print("ERROR: Config file 'data/config_default.json' not found")
    exit()
config = json.load(file)
config['Network']['SSID'] = SSID
config['Network']['Password'] = Password
file.seek(0)
json.dump(config,file,indent=4)
file.truncate()
file.close()
print("Wrote new SSID [" + SSID + "] and Password [" + Password + "] to config")