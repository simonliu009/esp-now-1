# OTA

It introduces a quick way to use `ESP-NOW` to upgrade devices.

## Process

<img src="../../docs/_static/en/OTA_workflow.png" width="550">

### Step 1: Connect to the router

Connect PC to the router that is connected to `ESP-NOW OTA Initator` network.

### Step 2: Run HTTP server

A built-in python HTTP server can be used as the server for the example upgrade.
Open a new terminal to run the HTTP server, and then run the below command to generate the firmware to be upgraded and start the server.
```shell
cd $IDF_PATH/examples/get-started/hello_world/
idf.py build
cd build
python -m SimpleHTTPServer 8070
```

While running the server, you may go to `http：// localhost：8070/` to browse the build directory.

> Note:
> 
	1. The above command may vary from systems. For some systems, the last command line may be `python2 -m SimpleHTTPServer 8070`.
	2. If there are firewall softwares that prevent any access to the port 8070, please grant the access while the example is running.

### Step 3: Build an OTA example

Navigate to the OTA example directory, and type `idf.py menuconfig` to configure the OTA example. 

Set following parameters under `Example Configuration` Options:
* Set `WiFi SSID` of the Router (Access-Point).
* Set `WiFi Password` of the Router (Access-Point).
* Set `IP version` of the example to be IPV4 or IPV6.
* Set `Port` number that represents remote port the example will create.

Set following parameter under `ESP-NOW OTA Example Configuration` Options:
* Set ESP-NOW OTA mode
* Set firmware upgrade URL。
  
```
https://<host-ip-address>:<host-port>/<firmware-image-filename>

for e.g,
https://192.168.0.3:8070/hello-world.bin
```

### Step 4: Flash the OTA example

When downloading the flash, please firstly use `erase_flash` to erase the entire flash memory (all the remaining data in ota_data partition will be deleted as well), and then write the followings via a serial port:

```shell
idf.py erase_flash flash
```

### Step 5: Run the OTA example

When the example starts up, it will print "Starting OTA example..." then:

1. Connect to the AP with configured SSID and password.
2. Connect to the HTTP server and download the new image.
3. Write the image to flash, and configure the next boot from this image.
4. Reboot

## Troubleshooting

* Check your PC can ping the ESP32 at its IP, and that the IP, AP and other configuration settings are correct in menuconfig.
* Check if any firewall software is preventing incoming connections on the PC.
* Check whether you can get firmware (default hello-world.bin), by checking the output of following command:

 ```
 curl -v https：// <host-ip-address>：<host-port> / <firmware-image-filename>
 ```

* If you have another PC or a phone, try viewing the file listing from the separate host.

### errors “ota_begin error err = 0x104”

If you see this error then check that the configured (and actual) flash size is large enough for the partitions in the partition table. The default "two OTA slots" partition table only works with 4 MB flash size. To use OTA with smaller flash sizes, create a custom partition table CSV (look in components/partition_table) and configure it in menuconfig.
