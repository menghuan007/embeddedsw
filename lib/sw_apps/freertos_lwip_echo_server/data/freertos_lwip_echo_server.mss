
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = freertos823_xilinx
 PARAMETER STDIN =  *
 PARAMETER STDOUT = *
END

BEGIN LIBRARY
 PARAMETER LIBRARY_NAME = lwip141
 PARAMETER API_MODE = SOCKET_API
 PARAMETER dhcp_does_arp_check = true
 PARAMETER lwip_dhcp = true
END
