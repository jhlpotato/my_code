// five_meta_info struct
struct five_meta_info {
	int type;	// ipv4 or ipv6
	char *src_ip;	// source ip
	char *des_ip;	// destination ip
	int src_port;	// source port
	int des_port;	// destination port;
	int protocol;	// portocol, udp or tcp
};

// bloomfilter struct
struct bloomfilter {
	int type;		// single-type bloomfilter or double-type bloomfilter
	char *bits;		// bits storage
	int bitlen;		// storage_len;
	int hashnums;	// hash function numbers; between 1-10
	int interval_time;	// store_into_file interval time; format_file binary file, timestamp.ipv4 or timestamp.ipv6
	int combinations;	// if type == double-type; the combinations numbers 2-15; default == 1, single-type
};

// bloomfilter configuer file
[bloomfilter]
bloomfilter_type = 0
bloomfilter_bitlen = 0
bloomfilter_hashnums = 0
bloomfilter_interval_time = 1
bloomfilter_combinations = 1

// request_packet_data struct
struct request_packet_data {
	int type;	// ipv4 or ipv6
	int timestamp;	// request timestamp;
	char *request_ip;	// request ip address;
	struct five_meta_info;	// five meta information;
	int path_length;	// traceback path length;
	struct *traceback_info;	// traceback path information;
};

//traceback_info struct
struct traceback_info {
	int type;	// ipv4 or ipv6;
	char *traceback_ip;	// trackback ip address;
}
