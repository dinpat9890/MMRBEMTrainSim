logman create counter System_Log -s %1 -f bin -v mmddhhmm -max 1000 -c "\LogicalDisk(*)\*" "\Memory\*" "\Network Interface(*)\*" "\Paging File(*)\*" "\PhysicalDisk(*)\*" "\Process(*)\*" "\Redirector\*" "\Server\*" "\System\*" -si 1
logman start counter System_Log -s %1
